#include<bits/stdc++.h>
using namespace std;


// This function is useful for shifting (circular) the array n positions towards left
void shift(vector<int>& ar, int n) {
    while (n > 0) {
        int temp = ar[0]; //store 0th bit
        for (int i = 0; i < ar.size() - 1; i++) {
            ar[i] = ar[i + 1];
        }
        ar[ar.size() - 1] = temp;  //put 0th bit to last posn
        n--;
    }
}

void keyGeneration(vector<int> key) {
    vector<int> key1(8,0);
    vector<int> key2(8,0);
    vector<int> P10 {3, 5, 2, 7, 4, 10, 1, 9, 8, 6};
    vector<int> P8 {6, 3, 7, 4, 8, 5, 10, 9};
    vector<int> P10key(10);
    
    //permutation using P10
    for (int i = 0; i < 10; i++) {
        P10key[i] = key[P10[i] - 1];
    }

    vector<int> Ls(5);
    vector<int> Rs(5);
    //divide P10 key to 2 halves
    for (int i = 0; i < 5; i++) {
        Ls[i] = P10key[i];
        Rs[i] = P10key[i + 5];
    }
    //left shift once
    shift(Ls, 1);
    shift(Rs, 1);
    
    //put it back in P10 key
    for (int i = 0; i < 5; i++) {
        P10key[i] = Ls[i];
        P10key[i + 5] = Rs[i];
    }
    
    //permutate using P8 and get key1
    for (int i = 0; i < 8; i++) {
        key1[i] = P10key[P8[i] - 1];
    }
    
    //left shift twice
    shift(Ls, 2);
    shift(Rs, 2);
    
    //combine both parts to P10
    for (int i = 0; i < 5; i++) {
        P10key[i] = Ls[i];
        P10key[i + 5] = Rs[i];
    }
    
    //permutate using P8 and get key2
    for (int i = 0; i < 8; i++) {
        key2[i] = P10key[P8[i] - 1];
    }

    // print key1
    for (int i = 0; i < 8; i++)
        cout << key1[i];
    cout << endl;
    
    //print key2
    for (int i = 0; i < 8; i++)
        cout << key2[i];
}



int main() {
    vector<int> key;
    long long binaryNum;
    cin>>binaryNum;
    for(int i=0; i<10; i++){
        int digit = binaryNum % 10;
        key.insert(key.begin(), digit);  // Insert at the beginning to maintain order
        binaryNum /= 10;
    }
    //for(int c:key) cout<<c<<" ";
    keyGeneration(key);
    
    return 0;
}
