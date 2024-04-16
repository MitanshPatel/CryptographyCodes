#include <bits/stdc++.h>
using namespace std;

pair<int, pair<int, int>> extendedEuclid(int b, int a) {
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
    return {a,{y1, x1}};
}
 
int modInverse(int a, int m) {
    return (extendedEuclid(a, m).second.first+m)%m; //just in case if negative
}

int main(){
    int a, m;
    cin>>a>>m;
    cout<<modInverse(a, m)<<endl;
}