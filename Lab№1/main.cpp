#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double x,a,c, dodanok1, dodanok2, znamennyk,vidpovid, korViraz;
    cout<<"Vvedit x: ";
    cin>>x;
    cout<<"Vvedit a: ";
    cin>>a;
    cout<<"Vvedit c: ";
    cin>>c;

    dodanok1=sqrt(exp(x)-pow(cos(pow(x,2)*pow(a,5)),4));
    //cout<<"dodanok 1 "<<dodanok1<<endl;
    korViraz=exp(x)-pow(cos(pow(x,2)*pow(a,5)),4);
    dodanok2=pow(atan(a-pow(x,5)),4);
    //cout<<"dodanok 2 "<<dodanok2<<endl;
    znamennyk=sqrt(fabs(a+x*pow(c,4)));
    //cout<<"znamennyk "<<znamennyk<<endl;
    if (znamennyk==0 ||korViraz<0){
        cout<<"Vidpovidi nemaye";
        }
    else {
        vidpovid=(dodanok1+dodanok2)/znamennyk;
        cout<<"vidpovid "<<vidpovid;
        }
    return 0;
}
