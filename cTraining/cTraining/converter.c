#include<stdio.h>
#include<math.h>
#include<stdbool.h>
#include<ctype.h>
#include<stdlib.h>
#include<malloc.h>
long int i;
long int h;
long int arr[128];
long int rev[128];
long long int n=1;
void Hex (long long int  n, int* ptr);

/// <summary>This function get the decimal value from user and display the Binary and Hexadecimal value for the given decimal value.</summary>
void BinaryAndHexConverter (long long int n);

int main () {
	//case:pass the decimal value
	printf ("Important:\n");
	printf ("Please Enter the Number only!\n");
	printf ("Please don't enter more then 11 digits number!");
	printf ("If you want to exit enter [q]");
	char c;
	char arr[100];
	int i = 0;
	printf ("\n");
	const char* str = arr;
	char* endptr=NULL;
	int it = 0;
	printf ("Input:");
	while ((c = getchar ()) != 'q') {
		bool Inv = false;
		arr[i] = c;
		int key = 0;
		if ((c == '\n')) {
			for (int j = 0; j <= i; j++) {
				if (isalpha (arr[j])|| arr[0] == '\n'||ispunct(arr[j])||arr[j]==' '||i>12) {
					if (arr[0] == '-'&&(!isalpha(arr[j])))continue;
					else {
						Inv = true;
						break;
					}
				}	
			}
			if (Inv) {
				printf ("Invalid!\n");
				const int n = 0;
			}
			else {
				n = strtoll(str,&endptr,10);
				if (n == 0) {
					printf ("Binary:%d\n", 0);
					printf ("HEX:%d\n", 0);
				} else BinaryAndHexConverter (n);
			}
			i = -1;
		}
		i++;
		it = 1;
		if (i==0 && it > 0) printf ("Input:");
	}
}

void BinaryAndHexConverter (long long int n) {
	i = 0;
	long long int temp= n,m = 0;
	//if the given integer is signed value 
	if (n < 0) {
		for (n; n < 0; n++)m++; //this for loop convert negative value to postive value
		n = m;
		printf ("Binary:");
		//converted to binary
		while (n > 0) {
			arr[i] = n % 2;
			n = round (n / 2);
			i++;
		}
		for (int a = i-1 , b = 0; b <= i-1 ; b++, a--) {
			//(arr[a] == 0)? rev[b] = 1:rev[b] = 0;
			rev[b] = (arr[a] == 0) ? 1 : 0;
		}
		//if the digit is 8 or less then 8
		if (i <=7 && i >= 0) {
			int j = 0,z;
			//span and invert(1's compliment)
			for (j; j <= 7 - i; j++) arr[j] = 1;
			for (int x = 0; x < i; x++) {
				arr[j++] = rev[x];
				h = j-1 ;
				z = h;
			}
			//add 1 at last digit(2's compliment)
			if (z == 7) {
				if ((arr[z] == 1)) {
					while (((arr[z] += 1) == 2)) {
						arr[z] = 0;
						z--;
					}
				} else arr[h] = 1;
			}
		//if the digit is 16 or less then 16
		} else if (i <= 15 && i >= 8) {
		   int j = 0,z ;
			for (j; j < 16 - i; j++) arr[j] = 1;
			for (int x = 0; x < i; x++) {
				arr[j++] = rev[x];
				h = j-1 ;
				z = h;
			}
			if (z == 15) {
				if ((arr[z] == 1)) {
					while (((arr[z] += 1) == 2)) {
						arr[z] = 0;
						z--;
					}
				} else arr[h] = 1;
			}
		//if the digit is 16 or less then 16
		} else if (i <= 31 && i >= 16) {
			int j = 0,z;
			for (j; j < 32 - i; j++) arr[j] = 1;
			for (int x = 0; x < i; x++) {
				arr[j++] = rev[x];
				h = j-1 ;
				z = h;
			}
			if (z == 31) {
				if ((arr[z] == 1)) {
					while (((arr[z] += 1) == 2)) {
						arr[z] = 0;
						z--;
					}
				} else arr[h] = 1;
			}
		}
		//if the digit is 64 or less then 64
		else if(i<=63 && i>=32) {
			int j = 0,z;
			for (j; j < 64 - i; j++) arr[j] = 1;
			for (int x = 0; x < i; x++) {
				arr[j++] = rev[x];
				h = j - 1;
				z = h;
			}
			if (z == 63) {
				if ((arr[z] == 1)) {
					while (((arr[z] += 1) == 2)) {
						arr[z] = 0;
						z--;
					}
				} else arr[h] = 1;
			}
		}
	}
	//else given integer unsigned value
	else {
		temp = n;
		int j = 0;
		printf ("Binary:");
		while (n > 0) {
			arr[i] = n % 2;
			i++;
			n = round (n / 2);
		}
		for (int a = i-1, b = 0; b <= i-1; b++, a--) rev[b] = arr[a];
		if (i <=7 && i >= 0) {
			for (j; j < 8 - i; j++) arr[j] = 0;
			for (int x = 0; x < i; x++)arr[j++] = rev[x];
		} else if (i <= 15 && i >= 8) {
			for (j; j < 16 - i; j++) arr[j] = 0;
			for (int x = 0; x < i; x++) arr[j++] = rev[x];
		} else if (i <= 31 && i >= 16) {
			for (j; j < 32 - i; j++) arr[j] = 0;
			for (int x = 0; x < i; x++) arr[j++] = rev[x];
		}
		else {
			for (j; j < 64 - i; j++) arr[j] = 0;
			for (int x = 0; x < i; x++) arr[j++] = rev[x];
		}
		h = j-1;
	}
	int* ptr;
	ptr = &arr[0];
	int stepin = 0;
	for (long int k = 0; k <= h; k++) { 
		if ((arr[k] == 0) && (stepin == 0)) continue;
		else {
			printf ("%d", arr[k]);
			stepin = 1;
		}
	}
	Hex (temp, ptr);
}
/// <summary>it's return the 2 power of given value</summary>
int Power (int m) {
	int mul=1;
	for (int i = 0; i < m; i++) mul *= 2;
	return mul;
}

/// <summary> This function called by BinaryAndHexConverter function and get binary values from that function and print hexadecimal value</summary>
void Hex (long long int  n,int *ptr) {
	printf ("\n");
	i = 0;
	int m = 0,stepin = 0;
	printf ("HEX:");
	//Binary value converted into hexadecimal
	for (int k = 0; k < (h + 1) / 4; k++) {
		int sum = 0;
		for (int j = 0, x = 3; j < 4; x--, j++) {
			sum += (*ptr) * Power (x);
			ptr++;
		}
		if ((sum == 0) && (stepin == 0)) continue;
		else {
			if (sum < 10) printf ("%d", sum);
			else printf ("%c", sum + 55);
			stepin = 1;
		}
	}
	printf ("\n");
}