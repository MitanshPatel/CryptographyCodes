// Input:
// PT: rendezvous
// Key: ace

// Output:
// New key generated: aceaceacea
// Encrypted text: rgrdgdvqys
// Decrypted text: rendezvous

// C++ code to implement Vigenere Cipher
#include<bits/stdc++.h>
using namespace std;

// This function generates the key in
// a cyclic manner until it's length isn't
// equal to the length of original text
string generateKey(string str, string key)
{
	int x = str.size();

	for (int i = 0; ; i++)
	{
		if (x == i)
			i = 0;
		if (key.size() == str.size())
			break;
		key.push_back(key[i]);
	}
	return key;
}

// This function returns the encrypted text
// generated with the help of the key
string cipherText(string str, string key)
{
	string cipher_text;
    int p=str.size();
	for (int i = 0; i < p; i++)
	{
		// converting in range 0-25
		int x = ((str[i]-97) + (key[i]-97))%26;

		// convert into alphabets(ASCII)
		char y=x+97;

		cipher_text.push_back(y);
	}
	return cipher_text;
}

// This function decrypts the encrypted text
// and returns the original text
string originalText(string cipher_text, string key)
{
	string orig_text;
    int q=cipher_text.size();
	for (int i = 0 ; i < q; i++)
	{
		// converting in range 0-25
		int x = ((cipher_text[i]-97) - (key[i]-97))%26;
        if(x<0){ x+=26; }
		// convert into alphabets(ASCII)
		char y=x+97;
		orig_text.push_back(y);
	}
	return orig_text;
}

// Driver program to test the above function
int main()
{
	string str, keyword;
	cin>>str>>keyword;

	string key = generateKey(str, keyword);
	cout<<"New key generated: "<<key<<endl;
	string cipher_text = cipherText(str, key);

	cout << "Encrypted text: "
		<< cipher_text << "\n";

	cout << "Decrypted text: "
		<< originalText(cipher_text, key);
	return 0;
}
