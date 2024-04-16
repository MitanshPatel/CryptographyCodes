// Find the third-round key of AES 128 using the following second round key which is given in hexadecimal,
// S-Box table and round constant 04.

#include <bits/stdc++.h>
using namespace std;

// AES S-Box (you need to provide the actual S-Box values)
unordered_map<unsigned char, unsigned char> sBox;

// AES Rcon table for round constants
const unsigned char Rcon[10] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1B, 0x36};

int main()
{
    // Replace the following with your actual second-round key in hexadecimal
    const unsigned char secondRoundKey[16] = {0x56, 0xC7, 0x76, 0xA0, 0x08, 0x1A, 0x43, 0x3A, 0x20, 0xB1, 0x55, 0xF7, 0x07, 0x8F, 0x69, 0xFA};
    // make sbox
    sBox.insert({0x3A, 0x80});
    sBox.insert({0xF7, 0x68});
    sBox.insert({0xFA, 0x2D});
    sBox.insert({0xA0, 0xE0});
    // Placeholder for the third-round key
    unsigned char thirdRoundKey[16];

    // Copy the second-round key to the third-round key as a starting point
    for (int i = 0; i < 16; ++i){
        thirdRoundKey[i] = secondRoundKey[i];
    }

    unsigned char temp[4];

    // Rotate word and XOR with rcon.
    // get g(w3) stored in temp array
    temp[0] = sBox[thirdRoundKey[7]] ^ Rcon[2];
    temp[1] = sBox[thirdRoundKey[11]];
    temp[2] = sBox[thirdRoundKey[15]];
    temp[3] = sBox[thirdRoundKey[3]];

    // find w4 = w0 ^ g(w3) and put it in thirdRoundKey[0,4,8,12] ie the 0th col
    for (int j = 0; j < 16; j += 4){
        thirdRoundKey[j] = thirdRoundKey[j] ^ temp[j / 4];
    }

    // XOR with the previous word
    // eg: w5 = w1 ^ w4
    // to fill col 1, 2, 3
    for (int i = 1; i < 4; i++){
        for (int j = i; j < 16; j += 4){
            thirdRoundKey[j] = thirdRoundKey[j] ^ thirdRoundKey[j - 1];
        }
    }

    // Display the third-round key
    for (int i = 0; i < 16; ++i){
        cout << "0x" << uppercase << hex << setw(2) << setfill('0') << (int)thirdRoundKey[i] << " ";
        if((i+1) % 4 == 0) cout<<endl;

    }
    cout << endl;

    return 0;
}

