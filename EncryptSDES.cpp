#include <bits/stdc++.h>
using namespace std;

const int IP[] = {2, 6, 3, 1, 4, 8, 5, 7};
const int IP_inv[] = {4, 1, 3, 5, 7, 2, 8, 6};
const int EP[] = {4, 1, 2, 3, 2, 3, 4, 1};
const int P4[] = {2, 4, 3, 1};

const int S0[4][4] = {{1, 0, 3, 2},
                      {3, 2, 1, 0},
                      {0, 2, 1, 3},
                      {3, 1, 3, 2}};

const int S1[4][4] = {{0, 1, 2, 3},
                      {2, 0, 1, 3},
                      {3, 0, 1, 0},
                      {2, 1, 0, 3}};

//convert bits to number
int BitToNum(int a, int b) {
    if(a==1 && b==1) return 3;
    else if(a==1 && b==0) return 2;
    else if(a==0 && b==1) return 1;
    return 0;
}

void function_(vector<int> &ar, vector<int> key_) {
    vector<int> l(4), r(4);

    for (int i = 0; i < 4; i++) {
        l[i] = ar[i];
        r[i] = ar[i + 4];
    }
    

    vector<int> ep(8);
    for (int i = 0; i < 8; i++) {
        ep[i] = r[EP[i] - 1];
    }
    

    for (int i = 0; i < 8; i++) {
        ar[i] = key_[i] ^ ep[i];
    }

    vector<int> l_1(4), r_1(4);
    for (int i = 0; i < 4; i++) {
        l_1[i] = ar[i];
        r_1[i] = ar[i + 4];
    }

    int row, col, val;

    row = BitToNum(l_1[0], l_1[3]);
    col = BitToNum(l_1[1], l_1[2]);
    val = S0[row][col];
    string str_l = (val == 0) ? "00" : ((val == 1) ? "01" : ((val == 2) ? "10" : "11"));

    row = BitToNum(r_1[0], r_1[3]);
    col = BitToNum(r_1[1], r_1[2]);
    val = S1[row][col];
    string str_r = (val == 0) ? "00" : ((val == 1) ? "01" : ((val == 2) ? "10" : "11"));

    vector<int> r_(4);
    for (int i = 0; i < 2; i++) {
        r_[i] = str_l[i] - '0';
        r_[i + 2] = str_r[i] - '0';
    }

    vector<int> r_p4(4);
    for (int i = 0; i < 4; i++) {
        r_p4[i] = r_[P4[i] - 1];
    }

    for (int i = 0; i < 4; i++) {
        l[i] = l[i] ^ r_p4[i];
    }

    for (int i = 0; i < 4; i++) {
        ar[i] = l[i];
        ar[i + 4] = r[i];
    }

}

void swap1(vector<int>& array, int n) {
    vector<int> l(n), r(n);

    for (int i = 0; i < n; i++) {
        l[i] = array[i];
        r[i] = array[i + n];
    }

    for (int i = 0; i < n; i++) {
        array[i] = r[i];
        array[i + n] = l[i];
    }

}

void encryption(vector<int> plaintext, vector<int> key1, vector<int> key2) {
    vector<int> arr(8);

    for (int i = 0; i < 8; i++) {
        arr[i] = plaintext[IP[i] - 1];
    }

    function_(arr, key1);

    swap1(arr, arr.size() / 2);

    function_(arr, key2);

    vector<int> ciphertext(8);

    for (int i = 0; i < 8; i++) {
        ciphertext[i] = arr[IP_inv[i] - 1];
    }

    for(int d:ciphertext) cout<<d;
}

int main(){
    vector<int>plaintext, key1, key2;
    long long binaryNum;
    cin>>binaryNum;
    for(int i=0; i<8; i++){
        int digit = binaryNum % 10;
        plaintext.insert(plaintext.begin(), digit);  // Insert at the beginning to maintain order
        binaryNum /= 10;
    }
    cin>>binaryNum;
    for(int i=0; i<8; i++){
        int digit = binaryNum % 10;
        key1.insert(key1.begin(), digit);  // Insert at the beginning to maintain order
        binaryNum /= 10;
    }
    cin>>binaryNum;
    for(int i=0; i<8; i++){
        int digit = binaryNum % 10;
        key2.insert(key2.begin(), digit);  // Insert at the beginning to maintain order
        binaryNum /= 10;
    }
    encryption(plaintext, key1, key2);
}
