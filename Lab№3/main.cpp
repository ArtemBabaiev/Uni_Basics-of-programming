#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double x, eps;
    cout<<"Enter variables x"<<endl;
    cout<<"x = "; cin>>x;
    cout<<"Enter epsilon: "<<endl;
    cout<<"eps = "; cin>>eps;

    //�������� �������
    while (x==0){
        cout<<"Enter x (x is not equal to zero)"<<endl;
        cout<<"x = "; cin>>x;
    }
    while (eps<=0){
        cout<<"Enter epsilon (epsilon > 0)"<<endl;
        cout<<"eps = "; cin>>eps;
    }

    //��������� ���� ��� ��������� ����
    long double numerator, denominator, sum = 0, fact = 24, tym = 1;
    int k = 1;
    double oneToK=-1, xTo=pow(x,4);
    while (fabs(tym)>=eps){
        //���������� ��������
        fact*=(4+k);

        //���������� ���������
        numerator=oneToK*xTo;
        //���������� ���������
        denominator=fact;

        //�������� ����������
        if(denominator==0){
            cout<<"denominator = 0"<<endl;
            break;
        }

        tym=numerator/denominator;
        if (fabs(tym)>eps){
            sum+=tym;
            k++;
            oneToK*=-1;
        }
       // ��� �������� ������� � ����
        /*cout<<oneToK<<endl;
        cout<<"fact "<<fact<<endl;
        cout<<"d "<<denominator<<endl;
        cout<<"n "<<numerator<<endl;
        cout<<"t "<<tym<<endl;
        cout<<"s "<<sum<<endl;
        cout<<endl;*/

    }

    //�������� ������ ����
    cout<<"number of terms is "<<k<<endl;
    cout<<"Sum is "<<sum;
    return 0;
}
