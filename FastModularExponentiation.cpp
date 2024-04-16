// Apply fast modular exponentiation algorithm to solve the following.
// 11^137 mod 97 =3

// For example:

// Input	Result
// 11         3
// 137
// 97



#include <iostream>
using namespace std;
long long modular(long long base, long long exp, int mod)
{
    long long res = 1;
    while (exp > 0)
    {
        if (exp % 2 == 1)
            res = (res * base) % mod;
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return res;
}
int main()
{
    long long b, e;
    int mod;
    cout << "Enter Base : ";
    cin >> b;
    cout << "Enter Exponent: ";
    cin >> e;
    cout << "Enter Modular Value: ";
    cin >> mod;
    cout << modular(b, e, mod);
    return 0;
}