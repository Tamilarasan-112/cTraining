#define _CRT_SECURE_NO_WARNINGS  1
#include <windows.h>
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <string.h>

/// <summary>
/// This function will execute the FSM providing the input and output file names as arguments
/// </summary>
/// <param name="exeFilePathAndName"></param>
/// <param name="inputFilePathAndName"></param>
/// <param name="outputFilePathAndName"></param>
/// <returns></returns>
int ExecProgram (char* exeFilePathAndName, char* inputFilePathAndName, char* outputFilePathAndName);

/// <summary>
/// Test Harness
/// </summary>
/// <param name="argc"></param>
/// <param name="argv">argv[1] is the name of the FSM</param>
/// <returns></returns>
int main (int argc, char** argv) {
#define NTESTS 10
   printf ("FSM Test Harness\n");
   if (argc != 2) {
      printf ("Usage: %s <%s>\n,", argv[0], argv[1]);
      return -1;
   }
   char inputFile[20], ExpOutputFile[28];
   for (int i = 1; i <= NTESTS; i++) {
      sprintf (inputFile, "Inputfiles/ip%d.txt", i);
      sprintf (ExpOutputFile, "Referencefiles/Exp-op%d.txt", i);
      if (ExecProgram (argv[1], inputFile, "outputFile.txt") != 0)printf ("Error executing test %d\n", i);
      else {
         char expChar, actualChar;
         int bitNo = 0;
         bool isError = false;
         FILE* exOpFile = fopen (ExpOutputFile, "r"), * outFile = fopen ("outputFile.txt", "r");
         if (exOpFile && outFile) {
            while (fread (&actualChar, sizeof (char), 1, outFile) && fread (&expChar, sizeof (char), 1, exOpFile)) {
               bitNo++;
               if (actualChar == expChar) continue;
               else {
                  printf ("Error Testing <%s> ,Error at bit no: <%d>, Expected: <%c>,Actual: <%c>\n", inputFile, bitNo, expChar, actualChar);
                  isError = true;
               }
            }
            if (!isError)printf ("No error testing <%s>\n", inputFile);
         }
      }
   }
}

int ExecProgram (char* exeFilePathAndName, char* inputFilePathAndName, char* outputFilePathAndName) {
   char* cmdline = malloc (strlen (exeFilePathAndName) + strlen (inputFilePathAndName) + strlen (outputFilePathAndName) + 3);
   if (cmdline == NULL) {
      printf ("Unable to allocate memory\n");
      return 1;
   }
   sprintf (cmdline, "%s%s%s%s%s", exeFilePathAndName, " ", inputFilePathAndName, " ", outputFilePathAndName);

   // Set up structures for process information
   STARTUPINFOA si;
   PROCESS_INFORMATION pi;

   // Initialize memory for STARTUPINFO and PROCESS_INFORMATION structures
   ZeroMemory (&si, sizeof (si));
   si.cb = sizeof (si);
   ZeroMemory (&pi, sizeof (pi));

   // Attempt to create the process
   if (!CreateProcessA (
      NULL,            // Application name (NULL if using command line)
      cmdline,          // Command line (path to the executable)
      NULL,            // Process handle not inheritable
      NULL,            // Thread handle not inheritable
      FALSE,           // Set handle inheritance to FALSE
      0,               // No creation flags
      NULL,            // Use parent's environment block
      NULL,            // Use parent's starting directory
      &si,             // Pointer to STARTUPINFO structure
      &pi))            // Pointer to PROCESS_INFORMATION structure
   {
      // If CreateProcess fails, print an error message
      int err = GetLastError ();
      printf ("Failed to start process. Error: %lu\n", GetLastError ());
      free (cmdline);
      return 1;
   }

   // Wait until the process has finished execution
   WaitForSingleObject (pi.hProcess, INFINITE);

   // Close handles
   CloseHandle (pi.hProcess);
   CloseHandle (pi.hThread);

   free (cmdline);
   return 0;
}