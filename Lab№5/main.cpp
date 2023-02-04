#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

int main()
{
    int n, i, j;

    cout<<"Enter the dimension of the array (n<=20)"<<endl;
    cout<<"n = ";cin>>n;
    //�������� n
    while (n<=0 || n>20){
        cout<<"The dimension is not set correctly"<<endl<<"0 < n <= 20"<<endl;
        cout<<"n = ";cin>>n;
    }

    //��������� ������ �, � �� �������� � ����� �����
    double A[n][n], X[n], maxOfLine, minOfLine;
    srand(time(NULL));

    //�������� ����, � ����� ������ �������� �������� ������ � �� ����� ������ � ���������
    for (i=0; i<n; i++){
        for (j=0; j<n; j++){
            A[i][j]=rand()%100;

            //��� ����� �������� � ���������
            /*cout<<"Enter element "<<i<<";"<<j<<" ";
            cin>>A[i][j];*/
            cout.width(3);
            cout<<A[i][j]<<" | ";
            //���� �������� ����� �����, ���������� ��������� � ������ �������� ������ ��������
            if(j==0){
                maxOfLine=A[i][j];
                minOfLine=A[i][j];
            }
            //����� ������������� � ����������
            if (maxOfLine<=A[i][j])
                maxOfLine=A[i][j];
            if (minOfLine>=A[i][j])
                minOfLine=A[i][j];
        }
        cout<<endl;

        //���������� �� ���������� ������� �������� ������ �
        X[i]=0.5*(fabs(maxOfLine)+fabs(minOfLine));
    }
    //�������� ����� �
    cout<<"Vector X:"<<endl;
    for (i=0; i<n; i++){
        cout.width(3);
        cout<<X[i]<<" | ";
    }
    return 0;
}
