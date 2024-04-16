#include<iostream>
#include<math.h>
using namespace std;

//input: 17 2 2 5 1 (p,a,b,x,y)

int main(){
    int p;
    int a,b,x,y;
    cin>>p>>a>>b>>x>>y;
    int lambda, temp1;
    temp1=((3*x*x + a))%p; //numerator of lambda
    int temp2=2*y;  //denominator of lambda
    int t=1;
    while((temp2*t)%p != 1){  // to calculate inverse modulo
        t++;
    }
    lambda=(temp1*t)%p;
    int x1,y1;
    x1=((lambda*lambda-x-x)%p);
    if(x1<0) x1+=p;
    y1=((lambda*(x-x1)-y)%p);
    if(y1<0) y1+=p;
    cout<<x1<<" "<<y1<<endl;
}