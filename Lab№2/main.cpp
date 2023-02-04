#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double x,y,z,a,b,c,d;

    //Вводимо змінні
    cout<<"Umova #1: a<=b"<<endl;
    cout<<"Vvedit a, b: "<<endl;
    cin>>a>>b;

    //Перевірка заданої умови
    bool i=false;
    if (a>b){
        while (i==false){
            cout<<"Ne zadovilnyaye umovi: a<=b"<<endl;
            cout<<"Vvedit a, b she raz: ";
            cin>>a>>b;
            if (a<=b){
                i=true;
            }
        }
    }

    //Вводимо змінні
    cout<<"Umova #2: c<=d"<<endl;
    cout<<"Vvedit c,d : "<<endl;
    cin>>c>>d;

    //Перевірка заданої умови
    if (c>d){
        i=false;
        while (i==false){
            cout<<"Ne zadovilnyaye umovi: c<=d"<<endl;
            cout<<"Vvedit c, d she raz: ";
            cin>>c>>d;
            if (c<=d){
                i=true;
            }
        }
    }

    //Вводимо змінні
    cout<<"Vvedit x,y,z: ";
    cin>>x;
    cin>>y;
    cin>>z;

    //Перевірка
    /*if ((x==y) || (x==z) || (y==z)){
        i=false;
        while (i==false) {
            cout<<"x, y, z povynni buty riznymy: ";
            cin>>x>>y>>z;
            if ((x!=y) && (x!=z) && (y!=z)){
                i=true;
            }
        }
    }*/


    //Основна задача
    if ((x>=c && x<=d) && (y>=c && y<=d) && (z>=c && z<=d)) {
        //Рахуємо максимальне значення
        cout<<fmax(x,fmax(y,z));
   }
    else if ((x<c || x>d) && (y<c || y>d) && (z<c || z>d)) {
        //Рахуемо мінімальне значення
        cout<<fmin(x,fmin(y,z));
    }
    else {
        cout<<(a+b)/2;
    }

    return 0;
}








