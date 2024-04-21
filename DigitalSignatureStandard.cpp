#include<iostream>
#include<math.h>
using namespace std;

//input p, q, H(M), h, X, k (11, 5, 54, 2, 3, 3)

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
    int p,q,hm,h,x,k;
    cin>>p>>q>>hm>>h>>x>>k;
    int temp=(p-1)/q;
    int g=exponentMod(h,temp,p);
    // while(temp--){
    //     g=(g*h)%p;
    // }
    
    temp=x;
    int y=exponentMod(g,temp,p);
    // while(temp--){
    //     y=(y*g)%p;
    // }

    temp=k;
    int r=exponentMod(g,temp,p);
    // while(temp--){
    //     r=((r*g)%p);
    // }
    r=r%q;

    int kinv=inverseMod(k,q);
    // while((k*kinv)%q !=1) kinv++;
    int s;
    s=(kinv * (hm + x*r))%q;

    int w;
    int sinv=inverseMod(s,q);
    // while((s*sinv)%q != 1) sinv++;
    w=sinv%q;

    int u1;
    u1=(hm*w)%q;

    int u2;
    u2=(r*w)%q;

    temp=u1;
    int temp2=u2;
    int v=exponentMod(g,temp,p);
    v=v+exponentMod(y,temp2,p);
    v=v%q;
    // while(temp--){
    //     v=((v*g)%p);
    // }
    // while(temp2--){
    //     v=((v*y)%p);
    // }
    cout<<"r="<<r<<endl;
    cout<<"s="<<s<<endl;
    cout<<"w="<<w<<endl;
    cout<<"u1="<<u2<<endl;
    cout<<"u2="<<u1<<endl;
    cout<<"v="<<v<<endl;

}