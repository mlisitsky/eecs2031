#include <stdio.h>

/* Matthew Lisitsky - 212941506 */

int countDigits(int x, int d) {

	int digits[1000];
	int number = x;
	int finalcount = 0;
	int i = 0;

	if (x == 0) {
		if (d == 0) {
			return 1;
		}
		else {
			return 0;
		}
	}

	while (number != 0) {
		    digits[i] = number % 10;
		        number = number / 10;
			if (d == digits[i]) {
				finalcount++;
			}
			i++;
	}


	return finalcount;
}

int testCountDigits(int x, int d, int result, char *msg) {

	if (countDigits(x, d) == result) {
		printf("test passed %s", msg);
	}
	else {
		printf("test failed %s", msg);
	}

	return 0;
}

int main (int argc, char *argv[]) {

	testCountDigits(123, 1, 1, "single digit test");

	testCountDigits(10, 0, 1, "single 0 test");

	testCountDigits(456456, 4, 2, "two fours");

	testCountDigits(111111, 1, 6, "six 1's");
	
	return 0;
}


