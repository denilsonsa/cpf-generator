#include <stdio.h>

// Digits before the verification digits ("DV").
#define DIGITS 9
// All digits, including the verification ones.
#define MAX_DIGITS 11
// Extra characters for the dots and hyphen, and for newline and NULL.
#define MAX_STRING (MAX_DIGITS + 2 + 3)
// Change this between zero or one.
#define PRINT_FORMATTED 0

// Digits, stored as integers.
char digits[MAX_DIGITS];
// Characters, as a NULL-terminated string including a trailing newline.
char output[MAX_STRING];

void print() {
#if PRINT_FORMATTED
	output[ 0] = digits[ 0] + '0';
	output[ 1] = digits[ 1] + '0';
	output[ 2] = digits[ 2] + '0';
	output[ 3] =              '.';
	output[ 4] = digits[ 3] + '0';
	output[ 5] = digits[ 4] + '0';
	output[ 6] = digits[ 5] + '0';
	output[ 7] =              '.';
	output[ 8] = digits[ 6] + '0';
	output[ 9] = digits[ 7] + '0';
	output[10] = digits[ 8] + '0';
	output[11] =              '-';
	output[12] = digits[ 9] + '0';
	output[13] = digits[10] + '0';
	output[14] =              '\n';
	output[15] =              '\0';
#else
	int i = MAX_DIGITS + 2;
	output[--i] = '\0';
	output[--i] = '\n';
	while (i > 0) {
		--i;
		output[i] = digits[i] + '0';
	}
#endif
	fputs(output, stdout);
	// fwrite(output, 1, MAX_DIGITS + 1, stdout);
}

void calculate_dv() {
	int dv1 = 0;
	int dv2 = 0;
	int i;
	for (i = 0; i < DIGITS; ++i) {
		dv1 += digits[DIGITS - i - 1] * (9 - (i % 10));
		dv2 += digits[DIGITS - i - 1] * (9 - ((i + 1) % 10));
	}
	dv2 += dv1 * 9;
	digits[DIGITS]     = (dv1 % 11) % 10;
	digits[DIGITS + 1] = (dv2 % 11) % 10;
}

void recurse_generate(int index) {
	int d;
	for (d = 0; d < 10; ++d) {
		digits[index] = d;
		if (index + 1 == DIGITS) {
			calculate_dv();
			print();
		} else {
			recurse_generate(index + 1);
		}
	}
}

int main(int argc, char*argv[]) {
	recurse_generate(0);
	return 0;
}
