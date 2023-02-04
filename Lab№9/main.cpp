#include <iostream>
#include <ctime>
int AunionB(int* firstArray, int lengthOf1, int* secondArray, int lengthOf2, int* AuB);

int main()
{
    srand(time(NULL));
    int i, j;
    int *n = new int;
    int *m = new int;
    do{
        std::cout << "Enter n (n<=300)" << "\n";
        std::cout << "n = "; std::cin >> *n;
    } while (*n < 0 || *n>300);
    do {
        std::cout << "Enter m (m<=400)" << "\n";
        std::cout << "m = "; std::cin >> *m;
    } while (*m < 0 || *m > 300);

    int* A = new int[*n];
    int* B = new int[*m];

    std::cout << "Array A: " << "\n";
    for (i = 0; i < *n; i++) {
        *(A + i) = rand() % 30 + 1;
        std::cout << *(A+i) << " | ";
    }
    std::cout << "\n" << "Array B: " << "\n";
    for (i = 0; i < *m; i++) {
        *(B + i) = rand() % 30 + 1;
        std::cout << *(B + i) << " | ";
    }


    int *AUB = new int[*m + *n];
    int* dimOfAUB = new int( AunionB(A, *n, B, *m, AUB) );
    delete[] A;
    delete[] B;
    delete m;
    delete n;

    std::cout<< "\n"<< "AUB main "<< "\n";
    for (i=0; i<*dimOfAUB; i++){
        std::cout<<*(AUB + i)<< " | ";
    }
    delete dimOfAUB;
    delete [] AUB;
    return 0;
}


//------------------------------------------------------------------------------------------
#include <iostream>

int AunionB(int *firstArray, int lengthOf1, int *secondArray, int lengthOf2, int *AuB) {
    int *dimOfTA = new int (lengthOf1 + lengthOf2);
	int *TempArray = new int[*dimOfTA];
	int i, j, k=0, len=*dimOfTA;


	std::cout << "\n" << "Temporary Array: " << "\n";
	for (i = 0; i < lengthOf1; i++, k++) {
		*(TempArray + k) = *(firstArray + i);
		std::cout << *(TempArray + k) << " | ";
	}
	for (i = 0; i < lengthOf2; i++, k++) {
		*(TempArray + k) = *(secondArray + i);
		std::cout << *(TempArray + k) << " | ";
	}


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
			*(AuB + k) = *(TempArray + i);
			std::cout << *(AuB + k) << " | ";
			k++;
		}
	}
	delete dimOfTA;
	delete forOP;
	delete[] TempArray;
	return k;
}
