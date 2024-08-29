#include<stdio.h>
#include<math.h>
#include "converter.h"
long int i;
long int h;
long int arr[128];
int rev[128];
long long int n;
void Hex (long int  n, int* ptr);

void BinaryHex (long long int n) {
	printf ("\n");
	i = 0;
	long long int temp;
	temp = n;
	long long int m = 0;
	if (n < 0) {
		for (n; n < 0; n++)m++;
		n = m;
		printf ("Binary:");
		while (n > 0) {
			arr[i] = n % 2;
			n = round (n / 2);
			i++;
		}
		for (int a = i-1 , b = 0; b <= i-1 ; b++, a--) {
			if (arr[a] == 0) rev[b] = 1;
			else rev[b] = 0;
		}
		if (i <=7 && i >= 0) {
			int j = 0;
			int z;
			for (j; j <= 7 - i; j++) arr[j] = 1;
			for (int x = 0; x < i; x++) {
				arr[j++] = rev[x];
				h = j-1 ;
				z = h;
			}
			if (z == 7) {
				if ((arr[z] == 1)) {
					while (((arr[z] += 1) == 2)) {
						arr[z] = 0;
						z--;
					}
				} else arr[h] = 1;
			}
		} else if (i <= 15 && i >= 8) {
		   int j = 0;
			int z ;
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
		} else if (i <= 31 && i >= 16) {
			int j = 0;
			int z;
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
		else {
			int j = 0;
			int z;
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
			int z;
			for (j; j < 8 - i; j++) arr[j] = 0;
			for (int x = 0; x < i; x++)arr[j++] = rev[x];
		} else if (i <= 15 && i >= 8) {
			int z;
			for (j; j < 16 - i; j++) arr[j] = 0;
			for (int x = 0; x < i; x++) arr[j++] = rev[x];
		} else if (i <= 31 && i >= 16) {
			int z;
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

int power (int m) {
	int mul=1;
	for (int i = 0; i < m; i++) mul *= 2;
	return mul;
}

void Hex (long int  n,int *ptr) {
	printf ("\n");
	i = 0;
	int m = 0;
	int stepin = 0;
	printf ("HEX:");
	for (int k = 0; k < (h + 1) / 4; k++) {
		int sum = 0;
		for (int j = 0, x = 3; j < 4; x--, j++) {
			sum += (*ptr) * power (x);
			ptr++;
		}
		if ((sum == 0) && (stepin == 0)) continue;
		else {
			if (sum < 10) printf ("%d", sum);
			else printf ("%c", sum + 55);
			stepin = 1;
		}
	}
}