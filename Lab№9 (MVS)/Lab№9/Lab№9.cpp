#include <iostream>
#include <ctime>
//прототипи функцій
int AunionB(int* firstArray, int lengthOf1, int* secondArray, int lengthOf2, int* AuB);
void sumOfArray(int* AunionB, int length, int* sum);

int main()
{
    srand(time(NULL));
    int i;
    int* n = new int;
    int* m = new int;
    //вводимо розмірність
    do {
        std::cout << "Enter n (n<=300)" << "\n";
        std::cout << "n = "; std::cin >> *n;
    } while (*n < 0 || *n>300);
    do {
        std::cout << "Enter m (m<=400)" << "\n";
        std::cout << "m = "; std::cin >> *m;
    } while (*m < 0 || *m > 300);

    int* A = new int[*n];
    int* B = new int[*m];

    //Заповнюємо масив рандомними числами
    std::cout << "Array A: " << "\n";
    for (i = 0; i < *n; i++) {
        *(A + i) = rand() % 30 + 1;
        std::cout << *(A + i) << " | ";
    }
    std::cout << "\n" << "Array B: " << "\n";
    for (i = 0; i < *m; i++) {
        *(B + i) = rand() % 30 + 1;
        std::cout << *(B + i) << " | ";
    }

    //оголошуємо масив об'єднання, його теоретично можливий розмір та змінну для суми елементів
    int* AUB = new int[*m + *n];
    int* dimOfAUB = new int;   
    int* sum = new int(0);

    *dimOfAUB = AunionB(A, *n, B, *m, AUB);  //передаємо функції адреси перших елементів масивиів та їхні довжини
    
    //видаляємо не потрібні нам вже змінні та масиви
    delete[] A;
    delete[] B;
    delete m;
    delete n;
    
    sumOfArray(AUB, *dimOfAUB, sum); //викликаємо функцію та передаємо їй адресу першого елемента масива AUB, його довжину
                                     //та адресу змінної sum

    //Виводимо значення масиву об'єднання та суму
    std::cout << "\n" << "A union B(main): " << "\n";
    for (i = 0; i < *dimOfAUB; i++) {
        std::cout << *(AUB + i) << " | ";
    }
    std::cout<< "\n" << "Sum of elemets: " << *sum << "\n";
    
    delete sum;
    delete dimOfAUB;
    delete[] AUB;
    return 0;
}
