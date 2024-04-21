#include<iostream>
#include<math.h>
using namespace std;

//input : p, q, e, w (7, 13, 5, 35)

//to find base^exp % mod
int exponentMod(int base, int exp, int mod)
{
    int res = 1;
    while (exp > 0)
    {
        if (exp % 2 == 1)
            res = (res * base) % mod;
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return res;
}

//to find inverse
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
    int p,q,e,w;
    cin>>p>>q>>e>>w;
    int n=p*q;
    int phi = (p-1) * (q-1);
    
    int d=inverseMod(e,phi);
    
    int s=exponentMod(w,d,n);
    if(s<=0) s+=n;
    cout<<"s="<<s<<endl;

    int w1=exponentMod(s,e,n);
    if(w1<=0) w1+=n;
    cout<<"w calculated from s ="<<w1;
}