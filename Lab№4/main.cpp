#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int main() {
    //оголошуємо змінні
    int n;
    double a,b;

    cout<<"The array will contain elements with random values from 0 to 500"<<endl;
    //Вводимо зсінні
    cout<<"Enter variable n from 1 to 200"<<endl;
    cout<<"n = "; cin>>n;
    cout<<"Enter variables a, b (a<b)"<<endl;
    cout<<"a = "; cin>>a;
    cout<<"b = "; cin>>b;

    //Перевіряємо чи задовільняють введені числа умові
    while (n<=0 || n>200){
        cout<<"Variable n is invalid"<<endl;
        cout<<"n=(0,200]"<<endl;
        cout<<"n = "; cin>>n;
    }
    while (a>b ){
        cout<<"Variables a, b are invalid"<<endl<<"Enter variables a, b (a<b)"<<endl;
        cout<<"a = "; cin>>a;
        cout<<"b = "; cin>>b;
    }
    //Оголошємо змінні суми, добутку та масив Х
    double  sum=0, product=1;
    int X[n], i=0;

    //Задаємо рандомні значення в діапазоні від 0 до 500
    srand(time(NULL));
    while (i<n){
        X[i]=rand()%500+1;
        cout<<X[i]<<" | ";
        i++;
    }
    cout<<endl;
    //Оголошуємо зміні для основної задачі
    int forCase, again=1, numberOfOperations, minimum=b, maximum=a;
    while (again==1){
        //Зануляємо значення
        i=0;
        numberOfOperations=0;

        cout<<endl<<"__________________________________________________________"<<endl;

        //Вибір операції
        cout<<"Enter 1 if you want to find sum of all X[i]<a"<<endl;
        cout<<"Enter 2 if you want to find product of all X[i]>b"<<endl;
        cout<<"Enter 3 if you want to find sum for all X[i]<a"<<endl;
        cout<<"What do you want? "<<endl; cin>>forCase; cout<<endl;
        switch (forCase) {

            //Пошук суми
            case 1 :
                while (i<n){
                    if (X[i]<a){
                        sum+=X[i];
                        numberOfOperations++;
                    }
                    i++;
                }
                if (numberOfOperations==0)
                    cout<<"There are no elements <a";
                else{
                    cout<<"Sum of elements is "<<sum<<endl;
                }
                break;

            //Пошук добутку
            case 2 :
                while (i<n){
                    if (X[i]>b){
                        product*=X[i];
                        numberOfOperations++;
                    }
                    i++;
                }
                if (numberOfOperations==0)
                    cout<<"There are no elements >b"<<endl;
                else{
                    cout<<"The product of elements is "<<product<<endl;
                    }

                break;

            //Пошук максимуму і мінімуму
            case 3 :

                while (i<n){
                    if (X[i]>=a && X[i]<=b){
                        if (minimum>=X[i])
                            minimum=X[i];
                        if (maximum<=X[i])
                            maximum=X[i];

                        numberOfOperations++;
                    }
                    i++;
                }
                if (numberOfOperations==0)
                    cout<<"There are no elements a<= X[i] <=b";

                else{
                    cout<<"Minimum is "<<minimum<<endl;
                    cout<<"Maximum is "<<maximum<<endl;
                }
                break;
        }

        //Повторити операцію
        cout<<"Do you need something else?"<<endl<<"If yes enter 1. If no - 0"<<endl;
        cout<<"Again? "; cin>>again;
    }
    cout<<"____________________________________________________"<<endl<<"Task is complete"<<endl;
return 0;
}
