#include<iostream>
#include<math.h>
using namespace std;

//input: 17 2 2 5 1 (p,a,b,x,y)

int inverseMod(int b, int a) {
    int temp = a;
    int y1 = 0, y2 = 1;
    int x1 = 1, x2 = 0;
    int q, r, xtemp, ytemp;
    while (b != 0) {
        q = a / b;
        r = a % b;
        ytemp = y1 - q * y2;
        xtemp = x1 - q * x2;
        y1 = y2; 
        x1 = x2;
        y2 = ytemp; 
        x2 = xtemp;
        a = b; 
        b = r;
    }
    if(y1<0) y1 += temp;
    return y1;
}

int main(){
    int p;
    int a,b,x,y;
    cin>>p>>a>>b>>x>>y;
    int lambda, temp1;
    temp1=((3*x*x + a))%p; //numerator of lambda
    int temp2=2*y;  //denominator of lambda
    int t=inverseMod(temp2, p);
    lambda=(temp1*t)%p;
    int x1,y1;
    x1=((lambda*lambda-x-x)%p);
    if(x1<0) x1+=p;
    y1=((lambda*(x-x1)-y)%p);
    if(y1<0) y1+=p;
    cout<<x1<<" "<<y1<<endl;
}