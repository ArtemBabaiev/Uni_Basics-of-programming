#include <iostream>

void sumOfArray(int *AunionB, int length, int* sum) {
	int i;
	for (i = 0; i < length; i++) {
		*sum += *(AunionB + i);
	}
}