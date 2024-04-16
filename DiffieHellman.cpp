// Implement Diffie Hellman key exchange algorithm.
// Prime number(q)=7
// Primitive root(r) of 7 is 3
// Alice (Receiver):
//               Private key(a): 4
//               Compute public key
// Bob (Sender):
//               Private key(b): 5
//               Compute public key
// Exchange Public keys
// Bob (Sender):
//               Bob computes secret key(k)
// Alice (Receiver):
//               Alice also computes secret key(k)
// Inputs:
// Read q,r,a,b
// 7,3,4,5
// Output:
// Public key of Alice:4
// Public key of Bob:5
// Print the secret key calculated by Alice and Bob as 2

#include <cmath>
#include <iostream>
using namespace std;

int power(int a, int b, int P){
	if (b == 1) return a;

	else return (((int)pow(a, b)) % P);
}

int main(){
	int x, y, ca, cb;
	int q,r,a,b;

	cin>>q;
	cin>>r;
	cin>>a;
	cout<<"Public key of Alice:"<<a<<endl;

	x=power(r, a, q); // gets the generated key

	cin>>b;
	cout<<"Public key of Bob:"<<b<<endl;

	y=power(r, b, q); // gets the generated key

	ca=power(y, a, q);
	cb=power(x, b, q);
	cout<<"Secret key calculated by Alice:"<<ca<<endl;

	cout<<"Secret key calculated by Bob:"<<cb<< endl;

	return 0;
}
