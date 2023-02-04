#include <iostream>

int AunionB(int* firstArray, int lengthOf1, int* secondArray, int lengthOf2, int* AuB) {
	int* dimOfTA = new int(lengthOf1 + lengthOf2);
	int* TempArray = new int[*dimOfTA];
	int i, j, k = 0, len = *dimOfTA;


	//std::cout << "\n" << "Temporary Array: " << "\n";
	for (i = 0; i < lengthOf1; i++, k++) {
		*(TempArray + k) = *(firstArray + i);
		//std::cout << *(TempArray + k) << " | ";
	}
	for (i = 0; i < lengthOf2; i++, k++) {
		*(TempArray + k) = *(secondArray + i);
		//std::cout << *(TempArray + k) << " | ";
	}


	int* forOP = new int;
	k = 0;
	for (i = 0; i < *dimOfTA; i++) {
		*forOP = 0;
		for (j = i + 1; j < *dimOfTA; j++) {
			if (*(TempArray + i) == *(TempArray + j)) {
				*forOP += 1;
			}
		}
		if (*forOP == 0) {
			*(AuB + k) = *(TempArray + i);
			k++;
		}
	}
	delete dimOfTA;
	delete forOP;
	delete[] TempArray;
	return k;
}