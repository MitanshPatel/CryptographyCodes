#include <bits/stdc++.h> 
using namespace std; 

// to get multiplicative inverse
int extendedEuclid(int b, int a) {
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

int findMinX(vector<int> a, vector<int> m, int k){
	int M = 1;
	for (int i = 0; i < k; i++) 
		M *= m[i];

	int result = 0; 
 
	for (int i = 0; i < k; i++) { 
		int M1 = M / m[i]; 
		result += a[i] * M1*extendedEuclid(M1, m[i]); // a*M1*M1^-1
	}

	return result % M; 
} 

int main(void) { 
	vector<int> a;
	vector<int> m;
	for(int i=0; i<3; i++){
	    int x;
	    cin>>x;
	    a.push_back(x);
	    cin>>x;
	    m.push_back(x);
	}
	int k = a.size(); 
	cout<<findMinX(a, m, k); 
	return 0; 
}
