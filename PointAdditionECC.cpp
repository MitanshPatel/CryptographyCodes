#include<iostream>
#include<math.h>
using namespace std;

// input: p, a, b, x1, y1, x2, y2 (97, 2, 3, 17, 10, 95, 31)

int main(){
    int p;
    int a,b,x1,y1,x2,y2;
    cin>>p>>a>>b>>x1>>y1>>x2>>y2;
    int lambda, temp1, temp2, t=1;
    temp1=(y2-y1)%p; //numerator of lambda
    temp2=(x2-x1); //denominator of lambda
    while((temp2*t)%p!=1){  //inverse modulo
        t++;
    }
    lambda=(temp1*t)%p;
    int x3,y3;
    x3=((lambda*lambda-x1-x2)%p);
    if(x3<0) x3+=p; //if -5mod17 make it (-5+17)
    y3=((lambda*(x1-x3)-y1)%p);
    if(y3<0) y3+=p;
    cout<<x3<<" "<<y3<<endl;
}