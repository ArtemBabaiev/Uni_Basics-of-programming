#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    srand(time(NULL));
    setlocale(0, "");
    int i, j=0, k=0; //Індексні змінні
    int *n= new int;
    int *m= new int;

    //Вводимо розмірність масивів
    cout<<"Ведiть розмiрнiсть масиву А (n<=500)"<<endl;
    cout<<"n = "; cin>>*n;
    cout<<"Ведiть розмiрнiсть масиву B (m<=200)"<<endl;
    cout<<"m = "; cin>>*m;

    //Перевіряємо чи задовільнють розмірності вимогам
    while (*n<=0 || *n>500){
        cout<<"Змiнна n не задовiльняє умовi n<=500"<<endl;
        cout<<"n = "; cin>>*n;
    }
    while (*m<=0 || *m>200){
        cout<<"Змiнна m не задовiльняє умовi m<=500"<<endl;
        cout<<"m = "; cin>>*m;
    }

    //Оголошуємо динамічні масиви
    int *A=new int[*n];
    int *B=new int[*m];
    int *dimOfAUB= new int (*m+*n);//Оголошуємо динамічну змінну, яка буде визначати розмір масиву об'єднання без повторень
    int *TempArray = new int [*m+*n]; //Масив для об'єднання з повторюваними значеннями

    //Заповнюємо масив А
    cout<<endl<<"Масив А: "<<endl;
    for (i=0; i<*n; i++,  j++){
        A[i]=rand()%20;
        cout<<A[i]<<" | ";
        *(TempArray+j)=*(A+i);  //Додаємо елемент до тимчасового масиву
    }

    //Заповнюємо масив В
    cout<<endl<<"Масив В: "<<endl;
    for (i=0; i<*m; i++, j++){
        B[i]=rand()%20;
        cout<<B[i]<<" | ";
        *(TempArray+j)=*(B+i);  //Додаємо елемент до тимчасового масиву
    }

    //Вадляємо масиви А і В та змінні, які визначали розмір ци масивів
    delete[] A;
    delete[] B;
    int *dimOfTA= new int (*m+*n);//Вводми змінну, яка визначає розмір тимчасовго масиву. Економніше розмір задавати через 1 int ніж через 2 int
    delete[] m;
    delete[] n;

    cout<<endl;

    //Цикл в якому вираховуємо розмірність АUB без повторень
    for (i=0; i<*dimOfTA; i++){
        //cout<<TempArray[i]<<" | ";
        for(j=i+1; j<*dimOfTA; j++){
            if (*(TempArray+i)==*(TempArray+j)){
                *dimOfAUB-=1;
            }
        }
    }

    //Допоміжні змінні для обчислення суми, та додавання до масиву неповторюваних елементів
    int *forOp= new int;
    int *sum= new int (0);
    //Оголошення масиву об'єднання без повтору
    int *AUB= new int [*dimOfAUB];

    //Заповнюємо масив об'єднання
    for (i=0; i<*dimOfTA; i++){
        *forOp=0;
        for(j=i+1; j<*dimOfTA; j++){
            if (*(TempArray+i)==*(TempArray+j)){
                *forOp+=1;
                }
        }
        if (*forOp==0){
            *(AUB+k)=*(TempArray+i);
            *sum+=AUB[k];
            k++;
        }
    }
    //Видаляємо елементи, які відносяться до тимчасового масиву
    delete[] TempArray;
    delete[] dimOfTA;

    int *ptr=AUB;
    cout<<endl<<"Масив об'єднання AUB "<<endl;
    for (i=0; i<*dimOfAUB; i++)
        cout<<*(ptr+i)<<" | ";
    delete[] AUB;
    delete[] dimOfAUB;

    cout<<endl<<"Сума елементiв масиву: "<<*sum<<endl;
    delete[] sum;
    return 0;
}
