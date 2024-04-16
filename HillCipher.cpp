// Input
// BCA
// Key
// 6 24 1
// 13 16 10
// 20 17 15

// Inverse
//  8 5 10
//  21 8 21
//  21 12 8

// Result
// Encrypted text: CTC
// Decrypted text: BCA

#include <bits/stdc++.h>
using namespace std;

// to generate matrix from key
//  void getKeyMatrix(string key, int keyMatrix[][3]){
//  	int k = 0;
//  	for (int i = 0; i < 3; i++) {
//  		for (int j = 0; j < 3; j++) {
//  			keyMatrix[i][j] = (key[k]) % 65;
//  			k++;
//  		}
//  	}
//  }

void encrypt(int cipherMatrix[][1], int keyMatrix[][3], int messageVector[][1])
{
    int x, i;
    for (i = 0; i < 3; i++){
        cipherMatrix[i][0] = 0;
        for (x = 0; x < 3; x++){
            cipherMatrix[i][0] += keyMatrix[i][x] * messageVector[x][0];
        }
        cipherMatrix[i][0] = cipherMatrix[i][0] % 26;
    }
}

void decrypt(int decryMatrix[][1], int inverseMatrix[][3], int messageVector[][1])
{
    int x, i;
    for (i = 0; i < 3; i++)
    {
        decryMatrix[i][0] = 0;
        for (x = 0; x < 3; x++)
        {
            decryMatrix[i][0] += inverseMatrix[i][x] * messageVector[x][0];
        }

        decryMatrix[i][0] = decryMatrix[i][0] % 26;
        
    }
}

void HillCipher(string message, int keyMatrix[][3], int inverseMatrix[][3])
{
    // Encrypt
    int messageVector[3][1];
    int cipherMatrix[3][1];
    string CipherText;

    for (int i = 0; i < 3; i++)
        messageVector[i][0] = (message[i]) % 65;
    encrypt(cipherMatrix, keyMatrix, messageVector);

    for (int i = 0; i < 3; i++)
        CipherText += cipherMatrix[i][0] + 65;

    cout << "Encrypted text: " << CipherText << endl;

    // Decrypt
    int decryMatrix[3][1];
    string decry;

    for (int i = 0; i < 3; i++)
        messageVector[i][0] = (CipherText[i]) % 65;

    decrypt(decryMatrix, inverseMatrix, messageVector);

    for (int i = 0; i < 3; i++)
        decry += decryMatrix[i][0] + 65;

    cout << "Decrypted text: " << decry;
}

int main()
{
    string str;
    cin >> str;
    int keyMatrix[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int x;
            cin >> x;
            keyMatrix[i][j] = x;
        }
    }

    int inverseMatrix[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int x;
            cin >> x;
            inverseMatrix[i][j] = x;
        }
    }

    HillCipher(str, keyMatrix, inverseMatrix);

    return 0;
}
