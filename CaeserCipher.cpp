// Input	
// I stand 5th in our class
// 3

// Result
// Encrypted text: L vwdqg 8wk lq rxu fodvv
// Decrypted text: I stand 5th in our class

#include<bits/stdc++.h>
using namespace std;

string caesar(string str, int k){
    string ans = "";
    int n=str.length();
    for (int i = 0; i < n; i++) {
        if(str[i]==' ') ans+=' ';
        else if(isdigit(str[i])){
            int x=int(str[i]);
            x+=k;
            ans += char(x);
        }
        else if (isupper(str[i])){
            int x=int(str[i] + k - 65);
            ans += char(x % 26 + 65);
        }
        else{
            int x=int(str[i] + k - 97);
            ans += char(x % 26 + 97);
        }
    }

    return ans;
}

string decrypt(string str, int k){
    string ans = "";
    int n=str.length();
    for (int i = 0; i < n; i++) {
        if(str[i]==' ') ans+=' ';
        else if(isdigit(str[i])){
            int x=int(str[i]);
            x-=k;
            ans += char(x);
        }
        else if (isupper(str[i])){
            int x=int(str[i] - k - 65);
            ans += char(x % 26 + 65);
        }
        else{
            int x=int(str[i] - k - 97);
            ans += char(x % 26 + 97);
        }
    }

    return ans;
}

int main(){
    string str;
    int k;
    getline(cin,str);
    cin>>k;
    string ans1=caesar(str, k);
    string ans2=decrypt(ans1, k);
    cout<<"Encrypted text: "<<ans1<<endl;
    cout<<"Decrypted text: "<< ans2;
}