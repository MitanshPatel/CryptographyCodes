#include<iostream>
#include<math.h>
using namespace std;

//input: q, α, XA, k, hash of message (19,10, 16, 5, 14)

int main(){
    int q,al, XA, k, hm;
    cin>>q>>al>>XA>>k>>hm;
    //public key
    int YA=1;
    int temp=XA;
    while(temp--){
        YA=(YA*al)%q;
    }
    int s1=1, s2;
    temp=k;
    while(temp--){
        s1=(s1*al)%(q);
    }
    if(s1<=0) s1+=q;
    int kinv=1; //k inverse
    while( (k*kinv)%(q-1) !=1){
        kinv++;
    }
    s2 = kinv * (hm - (XA*s1)) % (q-1);
    if(s2<=0) s2+=(q-1);
    cout<<"s1="<<s1<<endl;
    cout<<"s2="<<s2<<endl;

    int v1=1, v2=1;
    temp=hm;
    while(temp--){
        v1=(v1*al)%q;
    }
    temp=s1;
    int temp2=s2;
    while(temp--){
        v2=(v2*YA)%q;
    }
    while(temp2--){
        v2=(v2*s1)%q;
    }
    cout<<"v1="<<v1<<endl;
    cout<<"v2="<<v2<<endl;
}