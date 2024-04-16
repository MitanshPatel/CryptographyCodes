#include<iostream>
#include<math.h>
using namespace std;

//input p, q, H(M), h, X, k (11, 5, 54, 2, 3, 3)

int main(){
    int p,q,hm,h,x,k;
    cin>>p>>q>>hm>>h>>x>>k;
    int g=1;
    int temp=(p-1)/q;
    while(temp--){
        g=(g*h)%p;
    }
    
    int y=1;
    temp=x;
    while(temp--){
        y=(y*g)%p;
    }

    int r=1;
    temp=k;
    while(temp--){
        r=((r*g)%p);
    }
    r=r%q;

    int kinv=1;
    while((k*kinv)%q !=1) kinv++;
    int s;
    s=(kinv * (hm + x*r))%q;

    int w;
    int sinv=1;
    while((s*sinv)%q != 1) sinv++;
    w=sinv%q;

    int u1;
    u1=(hm*w)%q;

    int u2;
    u2=(r*w)%q;

    int v=1;
    temp=u1;
    int temp2=u2;
    while(temp--){
        v=((v*g)%p);
    }
    while(temp2--){
        v=((v*y)%p);
    }
    v=v%q;
    cout<<"r="<<r<<endl;
    cout<<"s="<<s<<endl;
    cout<<"w="<<w<<endl;
    cout<<"u1="<<u2<<endl;
    cout<<"u2="<<u1<<endl;
    cout<<"v="<<v<<endl;

}