/*#include <iostream>

void AunionB(int *firstArray, int lengthOf1,int *secondArray, int lengthOf2) {
	int i, j, k=0;
	int *dimOfTA = new int (lengthOf1 + lengthOf2);
	int *TempArray = new int[*dimOfTA];
	std::cout << "\n" << "Temporary Array: " << "\n";
	for (i = 0; i < lengthOf1; i++, k++) {
		*(TempArray + k) = *(firstArray + i);
		std::cout << *(TempArray + k) << " | ";
	}
	for (i = 0; i < lengthOf2; i++, k++) {
		*(TempArray + k) = *(secondArray + i);
		std::cout << *(TempArray + k) << " | ";
	}
	int* dimOfAUB = new int(lengthOf1 + lengthOf2);
	for (i = 0; i < *dimOfTA; i++) {
		for (j = i + 1; j < *dimOfTA; j++) {
			if (*(TempArray + i) == *(TempArray + j)) {
				*dimOfAUB -= 1;
			}
		}
	}

	int *AUB = new int[*dimOfAUB];
	int *forOP= new int;
	k = 0;
	std::cout << "\n" << "A union B: " << "\n";
	for (i = 0; i < *dimOfTA; i++) {
		*forOP = 0;
		for (j = i + 1; j < *dimOfTA; j++) {
			if (*(TempArray + i) == *(TempArray + j)) {
				*forOP+=1;
			}
		}
		if (*forOP == 0) {
			*(AUB + k) = *(TempArray + i);
			std::cout << *(AUB + k) << " | ";
			k++;
		}
	}
}
*/
