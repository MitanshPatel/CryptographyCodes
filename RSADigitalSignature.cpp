#include<iostream>
#include<math.h>
using namespace std;

//input : p, q, e, w (7, 13, 5, 35)

int main(){
    int p,q,e,w;
    cin>>p>>q>>e>>w;
    int n=p*q;
    int phi = (p-1) * (q-1);
    //compute d
    int d=1;
    while((e*d)%phi != 1){ //to find inverse module
        d++;
    }
    int s=1;
    while(d--){   //to do pow(w,d) overflow happens, so do this method
        s=(s*w)%n;
    }
    if(s<=0) s+=n;
    cout<<"s="<<s<<endl;
    int w1=1;
    while(e--){
        w1=(w1*s)%n;
    }
    if(w1<=0) w1+=n;
    cout<<"w calculated from s ="<<w1;
}