#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double x, y, z;
    int k;
    bool i=false;

    //Вводимо змінні
    cout<<"vvedit zminni x, y, z: ";
    cin>>x>>y>>z;


    //введмо зманну k
    cout<<"Vvedit zile k dlya takyh umov:"<<endl<<"k=1 V=min(x,max(y,z))"<<endl<<"k=2 V=min(y,max(x,z))"<<endl<<"k=3 V=min(z,max(x,y))"<<endl<<"V=x+y+z dlya inshyh k"<<endl;
    cin>>k;



   //Основна задача
    switch(k) {
        case 1:
            cout<<"V = "<<fmin(x,fmax(y, z));
        break;
        case 2:
            cout<<"V = "<<fmin(y,fmax(x, z));
        break;
        case 3:
            cout<<"V = "<<fmin(z, fmax(x, y));
        break;
        default:
            cout<<"V = "<<x+y+z<<endl;
        break;
    }
    return 0;
}
