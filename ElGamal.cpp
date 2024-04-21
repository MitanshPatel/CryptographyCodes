// Implement El Gamal and Encrypt the following. The random number(q) assumed is 11. Primitive root (r) of 11 is 2. Message(m) to be encrypted is 8.
// Alice (Receiver):
//               Private key(a): 5
//               Compute public key
// Bob (Sender):
// Private key(b): 6
//               Compute public key
// Encryption:
// Bob (Sender):
//               Compute Cipher text (CT)
// Decryption:
// Alice (Receiver):
//              Compute Plain text (PT)

// Inputs:
// Read q, r, m, a, b
// 11, 2, 8, 5, 6
// Output:
// Public key of Alice:10
// Public key of Bob: 9
// Cipher text is 8
// Plain Text is 8


#include <iostream>
#include <cmath>

using namespace std;

int power(int x, unsigned int y, int p) {
    int res = 1;
    x = x % p;

    while (y > 0) {
        if (y & 1)
            res = (res * x) % p;

        y = y >> 1;
        x = (x * x) % p;
    }

    return res;
}

int modInverse(int a, int m) {
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;

    if (m == 1)
        return 0;

    while (a > 1) {
        q = a / m;
        t = m;

        m = a % m;
        a = t;
        t = x0;

        x0 = x1 - q * x0;
        x1 = t;
    }

    if (x1 < 0)
        x1 += m0;

    return x1;
}

//REFER THIS WEBSITE AND USE ITS FORMULA https://www.debjitbiswas.com/elgamal/
int main() {
    int q = 11; //p
    int r = 2; //g
    int m = 8; //msg
    int a_private = 5; //d
    int b_private = 6; //k

    // Alice (Receiver)
    int h_a = power(r, a_private, q); // Compute public key  // e
    cout << "Alice's Public Key (h_a): " << h_a << endl;

    // Bob (Sender)
    int h_b = power(r, b_private, q); // Compute public key  // e
    cout << "Bob's Public Key (h_b): " << h_b << endl;

    // Encryption (Bob)
    int c1 = power(r, b_private, q);
    int c2 = power(h_a,b_private,q)*m%q;
    cout << "Cipher Text is " << c1 <<" " <<c2 << endl;

    // Decryption (Alice)
    int s = power(c1, a_private, q);
    int s_inverse = modInverse(s, q);
    int decrypted_message = (c2 * s_inverse) % q;
    cout << "Decrypted Message: " << decrypted_message << endl;

    return 0;
}
