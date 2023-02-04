#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main()
{
    srand(time(NULL));
    //��������� ���� m, n ��� ������ ������, � ���� i, j, k ��� �������� �����
    int n, m, i, j, k=0, y=0;
    //������ �������� m �� n
    cout<<"Enter the dimension of the array A (n<=300)"<<endl;
    cout<<"n = ";cin>>n;
    cout<<"Enter the dimension of the array B (m<=200)"<<endl;
    cout<<"m = ";cin>>m;
    //�������� �����
    while (n<=0 || n>300){
        cout<<"The dimension is not set correctly"<<endl<<"0 < n <= 300"<<endl;
        cout<<"n = ";cin>>n;
    }
    while (m<=0 || m>200){
        cout<<"The dimension is not set correctly"<<endl<<"0 < m <= 200"<<endl;
        cout<<"m = ";cin>>m;
    }

    //��������� ������ �, � �� �� ������
    int A[n], B[m];

    //������ �������� �������
    cout<<endl<<"Array A: "<<endl;
    for (i=0; i<n; i++){
        A[i]=rand()%20;
        cout<<A[i]<<" | ";
    }
    cout<<endl<<"Array B: "<<endl;
    for (j=0; j<m; j++){
        B[j]=rand()%20;
        cout<<B[j]<<" | ";
    }
    cout<<endl<<"---------------------------------------------------------------------------------"<<endl;

    //��������� ������� ���� ��� ������ ������ ������
    int forOp, dimOfTA;

    //��������� ���������� �����, � ����� ���� �������� A/B ���� �/� � ������������� ����������
    //����� AsdB ��� ���������� ������
    int TempArray[m+n], AsdB[m+n];
    //���������� ����� ��� ������ �/� � ������������� ����������
    cout<<endl<<"Temp Array #1: "<<endl;
    for (i=0; i<n ;i++){
        forOp=0;
        for (j=0; j<m; j++){
            if (A[i]==B[j]){
                forOp++;
            }
        }
        if (forOp==0){
            TempArray[y]=A[i];
            cout<<TempArray[y]<<" | ";
            y++;
        }
    }
    dimOfTA=y;
    y=0;

    // ������ 1 ���������� ����� �� ������ ���������� ������
    for (i=0; i<dimOfTA; i++){
        forOp=0;
        for (j=i+1; j<dimOfTA; j++){
            if (TempArray[i]==TempArray[j])
                forOp++;
        }
        if (forOp==0){
            AsdB[k]=TempArray[i];

            k++;
        }
    }
    cout<<endl;

    //���������� ����� ��� ������ �/� � ������������� ����������
    cout<<endl<<"Temp array #2: "<<endl;
    for(j=0; j<m; j++){
        forOp=0;
        for (i=0; i<n; i++){
            if (B[j]==A[i]){
                forOp++;
            }
        }
        if (forOp==0){
            TempArray[y]=B[j];
            cout<<TempArray[y]<<" | ";
            y++;
        }
    }
    dimOfTA=y;
    y=0;

    // ������ 2 ���������� ����� �� ������ ���������� ������
    for (i=0; i<dimOfTA; i++){
        forOp=0;
        for (j=i+1; j<dimOfTA; j++){
            if (TempArray[i]==TempArray[j])
                forOp++;
        }
        if (forOp==0){
            AsdB[k]=TempArray[i];
            k++;
        }
    }
    cout<<endl<<"---------------------------------------------------------------------------------"<<endl;

    int dimOfSD=k; //����� ������ ���������� ������
    //�������� ����� ���������� ������, ��� �� ������������
    cout<<endl<<"Not sorted A similar difference B: "<<endl;
    for (i=0; i<dimOfSD;i++){
        cout<<AsdB[i]<<" | ";
    }

     //������������ ����� ���������� ������ ������� ������
     cout<<endl<<endl<<"Sorted A similar difference B: "<<endl;
     for (i=0;i<dimOfSD-1; i++){
            int smallest=i;
        for (j=i+1; j<dimOfSD; j++){
            if (AsdB[j]<AsdB[smallest]){
                smallest=j;
            }
        }
        swap(AsdB[smallest], AsdB[i]);
     }
     for (i=0;i<dimOfSD; i++){
        cout<<AsdB[i]<<" | ";
     }
        return 0;
}
