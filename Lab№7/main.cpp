#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    srand(time(NULL));
    setlocale(0, "");
    int i, j=0, k=0; //������� ����
    int *n= new int;
    int *m= new int;

    //������� ��������� ������
    cout<<"���i�� ����i��i��� ������ � (n<=500)"<<endl;
    cout<<"n = "; cin>>*n;
    cout<<"���i�� ����i��i��� ������ B (m<=200)"<<endl;
    cout<<"m = "; cin>>*m;

    //���������� �� ����������� ��������� �������
    while (*n<=0 || *n>500){
        cout<<"��i��� n �� �����i����� ����i n<=500"<<endl;
        cout<<"n = "; cin>>*n;
    }
    while (*m<=0 || *m>200){
        cout<<"��i��� m �� �����i����� ����i m<=500"<<endl;
        cout<<"m = "; cin>>*m;
    }

    //��������� ������� ������
    int *A=new int[*n];
    int *B=new int[*m];
    int *dimOfAUB= new int (*m+*n);//��������� �������� �����, ��� ���� ��������� ����� ������ ��'������� ��� ���������
    int *TempArray = new int [*m+*n]; //����� ��� ��'������� � ������������� ����������

    //���������� ����� �
    cout<<endl<<"����� �: "<<endl;
    for (i=0; i<*n; i++,  j++){
        A[i]=rand()%20;
        cout<<A[i]<<" | ";
        *(TempArray+j)=*(A+i);  //������ ������� �� ����������� ������
    }

    //���������� ����� �
    cout<<endl<<"����� �: "<<endl;
    for (i=0; i<*m; i++, j++){
        B[i]=rand()%20;
        cout<<B[i]<<" | ";
        *(TempArray+j)=*(B+i);  //������ ������� �� ����������� ������
    }

    //�������� ������ � � � �� ����, �� ��������� ����� �� ������
    delete[] A;
    delete[] B;
    int *dimOfTA= new int (*m+*n);//������ �����, ��� ������� ����� ���������� ������. ��������� ����� �������� ����� 1 int �� ����� 2 int
    delete[] m;
    delete[] n;

    cout<<endl;

    //���� � ����� ���������� ��������� �UB ��� ���������
    for (i=0; i<*dimOfTA; i++){
        //cout<<TempArray[i]<<" | ";
        for(j=i+1; j<*dimOfTA; j++){
            if (*(TempArray+i)==*(TempArray+j)){
                *dimOfAUB-=1;
            }
        }
    }

    //������� ���� ��� ���������� ����, �� ��������� �� ������ �������������� ��������
    int *forOp= new int;
    int *sum= new int (0);
    //���������� ������ ��'������� ��� �������
    int *AUB= new int [*dimOfAUB];

    //���������� ����� ��'�������
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
    //��������� ��������, �� ���������� �� ����������� ������
    delete[] TempArray;
    delete[] dimOfTA;

    int *ptr=AUB;
    cout<<endl<<"����� ��'������� AUB "<<endl;
    for (i=0; i<*dimOfAUB; i++)
        cout<<*(ptr+i)<<" | ";
    delete[] AUB;
    delete[] dimOfAUB;

    cout<<endl<<"���� �������i� ������: "<<*sum<<endl;
    delete[] sum;
    return 0;
}
