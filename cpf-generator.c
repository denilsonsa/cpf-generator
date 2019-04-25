#include <stdio.h>

#define DIGITS 9
#define MAX_DIGITS 11

signed char digits[MAX_DIGITS];
char output[MAX_DIGITS + 2];

void print() {
	int i = MAX_DIGITS + 2;
	output[--i] = '\0';
	output[--i] = '\n';
	while (i > 0) {
		--i;
		output[i] = digits[i] + '0';
	}
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
