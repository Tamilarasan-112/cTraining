// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ------------------------------------------------------------------
// Game.c
// Implemented the game for 2 players.
// ------------------------------------------------------------------------------------------------

#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <cType.h>
#include <string.h>

struct point {
   int player1;
   int player2;
};

typedef struct point points;

/// <summary>Display the board.</summary>
void Board (char arr[][5]);

/// <summary>Get the input from the player.</summary>
void Input (int* player);

/// <summary>Return true if input is valid,else false.</summary>
bool IsValidInput (char* playerInput);

/// <summary>Marks the player's symbol on the board.</summary>
void MarkSymbols (int player, char arr[][5], char* sym, int index, int* counts);

/// <summary>To manually test all the methods.</summary>
void ManualTest ();

/// <summary>To automatically test all the methods.</summary>
void AutomationTest ();

/// <summary>To test the MarkSymbols method.</summary>
int TestMarkSymbols (int input[], char expOut[][5]);

/// <summary>To test the Check method.</summary>
void TestCheck (char MarkedBoard[][5], int exp);

/// <summary>Displays the winner or indicates a draw match.</summary>
void DisplayWinner (int out);

/// <summary>To test the IsValidInput method.</summary>
void TestIsValidInput ();

int main () {
  //ManualTest ();
   AutomationTest ();
}

void MarkSymbols (int player, char arr[][5], char* sym, int index, int* counts) {
   if (player <= 3) {
      if (isdigit (arr[0][player - 1])) {
         arr[0][player - 1] = sym[index];
         (*counts)++;
      }
   } else if (player <= 6) {
      if (isdigit (arr[1][player - 4])) {
         arr[1][player - 4] = sym[index];
         (*counts)++;
      }
   } else {
      if (isdigit (arr[2][player - 7])) {
         arr[2][player - 7] = sym[index];
         (*counts)++;
      }
   }
}

int Check (char arr[][5], char* sym) {
   points row[3], column[3], diagonal1, diagonal2;
   diagonal1.player1 = 0;
   diagonal1.player2 = 0;
   diagonal2.player1 = 0;
   diagonal2.player2 = 0;
   //for intiallization
   for (int i = 0; i < 3; i++) {
      column[i].player1 = 0;
      column[i].player2 = 0;
   }
   for (int i = 0, k = 2; i < 3; i++, k--) {
      row[i].player1 = 0;
      row[i].player2 = 0;
      for (int j = 0; j < 3; j++) {
         if (arr[i][j] == sym[0]) {
            row[i].player1++;
            column[j].player1++;
            if (i == j) diagonal1.player1++;
            if (j == k) diagonal2.player1++;
         } else if (arr[i][j] == sym[1]) {
            row[i].player2++;
            column[j].player2++;
            if (i == j) diagonal1.player2++;
            if (j == k) diagonal2.player2++;
         }
         if (row[i].player1 == 3 || column[j].player1 == 3 || diagonal1.player1 == 3 || diagonal2.player1 == 3) {
            return 0;
         } else if (row[i].player2 == 3 || column[j].player2 == 3 || diagonal1.player2 == 3 || diagonal2.player2 == 3) {
            return 1;
         }
      }
   }
   return -1;
}

void Board (char arr[][5]) {
   for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 4; j++) {
         printf ("|%c", arr[i][j]);
      }
   }
}

void Input (int* player) {
   char* playerInput = malloc (4 * sizeof (char));
   if (playerInput != NULL) {
      do {
         fgets (playerInput, 4, stdin);
      } while (!(IsValidInput (playerInput)));
      *player = playerInput[0] - '0';
   }
}

bool IsValidInput (char* playerInput) {
   return strlen (playerInput) == 2 && (playerInput[0] >= '1' && playerInput[0] <= '9');
}

void StartGame () {
   char arr[10][5] = { { '1','2','3','\n' },{ '4','5','6','\n' },{ '7','8','9','\n' } };
   int player, it = 0, ret, i = 0, j = 0, counts = 0;
   bool isWin = false;
   char sym[3] = { '+','*' };
   Board (arr);
   while (!isWin) {
      it++;
      printf ("Player%d:", i + 1);
      Input (&player);
      MarkSymbols (player, arr, sym, i, &counts);
      Board (arr);
      if (it >= 5) {
         ret = Check (arr, sym);
         if (!ret) {
            printf ("\nPlayer1 is win\n");
            isWin = true;
         } else if (ret) {
            printf ("\nPlayer2 is win\n");
            isWin = true;
         } else if (counts == 9) {
            printf ("\nDraw");
            isWin = true;
         }
      }
      i++;
      if (i > 1) i = 0;
   }
}

void ManualTest () {
   StartGame ();
}

void AutomationTest () {
   int input1[9] = { 1,2,3,4,5,6,7,8,9 }, input2[9] = { 2,3,1,4,6,8,7,5,9 };
   char expout1[10][5] = { { '+','*','+','\n' },{ '*','+','*','\n' },{ '+','*','+','\n' } };
   char expout2[10][5] = { { '+','+','*','\n' },{ '*','*','+','\n' },{ '+','*','+','\n' } };

   printf ("\nTest MarkSymbols Method:\n");
   printf ("\nCase 1:\n");
   TestMarkSymbols (input1, expout1);
   printf ("\nCase 2:\n");
   TestMarkSymbols (input2, expout2);

   printf ("\nTest Check Method:\n");
   printf ("\nCase 1:\n");
   TestCheck (expout1, 0);
   printf ("\nCase 2:\n");
   TestCheck (expout2, -1);

   printf ("\nTest input validate Method:\n ");
   TestIsValidInput ();
}

int TestMarkSymbols (int input[], char expOut[][5]) {
   char arr[10][5] = { { '1','2','3','\n' },{ '4','5','6','\n' },{ '7','8','9','\n' } };
   char sym[3] = { '+','*' };
   int j = 0, i = 0, counts = 0;
   while (i < 9) {
      printf ("player%d:%d\n", j + 1, input[i]);
      MarkSymbols (input[i], arr, sym, j, &counts);
      j++;
      i++;
      if (j > 1) j = 0;
   }
   printf ("\nActual Output:\n");
   Board (arr);
   printf ("\nExpected OutPut:\n");
   Board (expOut);
   for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
         if (!(arr[i][j] == expOut[i][j])) {
            printf ("Failed!\n");
            return 0;
         }
      }
   }
   printf ("passed!\n");
   return 1;
}

void TestCheck (char MarkedBoard[][5], int exp) {
   int ret;
   char sym[3] = { '+','*' };
   printf ("\nInput:\n");
   Board (MarkedBoard);
   ret = Check (MarkedBoard, sym);
   printf ("\nExpected output:\n");
   DisplayWinner (exp);
   printf ("\nActual output:\n");
   DisplayWinner (ret);
   if (ret == exp) printf ("\nPassed!\n");
   else printf ("\nFailed!\n");
}

void TestIsValidInput () {
   char input[][5] = { "1\n","2\n","23\n","10\n","0\n","\n","s\n","-1\n","7\n" };
   int expout[] = { 1,1,0,0,0,0,0,0,1 }, ret;
   for (int i = 0; i < 9; i++) {
      ret = IsValidInput (input[i]);
      printf ("\ncase%d:\ninput:%sexpected:%d\nactual:%d", i + 1, input[i], expout[i], ret);
      if (ret == expout[i]) printf ("\nPassed!\n");
      else printf ("\nFailed!\n");
   }
}

void DisplayWinner (int out) {
   if (!out) printf ("player1 is win\n");
   else if (out) printf ("player2 is win\n");
   else printf ("match draw\n");
}