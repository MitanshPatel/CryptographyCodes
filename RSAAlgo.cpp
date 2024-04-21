// Implement RSA algorithm

// Message to be encrypted (m) is 4
// Let the two prime numbers (p and q) be 3 and 5. n=p*q
// Compute Euler’s totient function of φ(n) as 8
// Assume key for encryption ‘e’ as 5 
// Find key fordecryption ‘d’ satisfying the equation below.

// de mod φ(n)=1
// Find CT= m^e mod n
// Find PT= CT^d mod n
 
// Inputs:
// Read m, p, q, e
// 4,3,5,5
// Output:
// Cipher text is 4
// Plain Text is 4


// #include<iostream>
// #include<math.h>
// using namespace std;
// // find gcd
// int gcd(int a, int b) {
//    int t;
//    while(1) {
//       t= a%b;
//       if(t==0)
//       return b;
//       a = b;
//       b= t;
//    }
// }
// int main() {
//    //2 random prime numbers
//    double p = 13;
//    double q = 11;
//    double n=p*q;//calculate n
//    double track;
//    double phi= (p-1)*(q-1);//calculate phi
//    //public key
//    //e stands for encrypt
//    double e=7;
//    //for checking that 1 < e < phi(n) and gcd(e, phi(n)) = 1; i.e., e and phi(n) are coprime.
//    while(e<phi) {
//       track = gcd(e,phi);
//       if(track==1)
//          break;
//       else
//          e++;
//    }
//    //private key
//    //d stands for decrypt
//    //choosing d such that it satisfies d*e = 1 mod phi
//    double d1=1/e;
//    double d=fmod(d1,phi);
//    double message = 9;
//    double c = pow(message,e); //encrypt the message
//    double m = pow(c,d);  //for decrypt
//    c=fmod(c,n);
//    m=fmod(m,n);
//    cout<<"Original Message = "<<message;
//    cout<<"\n"<<"Encrypted message = "<<c;
//    cout<<"\n"<<"Decrypted message = "<<m;
//    return 0;
// }


//BETTER DO FROM THEORY, CODE IS COMPLEX

#include <iostream>
#include <math.h>
using namespace std;

int gcd(int a, int b){
    int t;
    while (1){
        t = a % b;
        if (t == 0)
            return b;
        a = b;
        b = t;
    }
}

int main(){
    double msg, p, q, e;
    cin>>msg>>p>>q>>e;
    double n = p * q;
    double track;
    double phi = 8;
    while (e < phi){
        track = gcd(e, phi);
        if (track == 1)
            break;
        else
            e++;
    }
    double d1=1/e;
    double d=fmod(d1,phi);
    double c = pow(msg, e); // encrypt the message
    double m = pow(c,d);  //for decrypt
    c=fmod(c, n);
    m=fmod(m,n);
    cout << "Cipher text is " << c<<endl;
    cout << "Plain Text is " << m;
    return 0;
}