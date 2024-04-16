// Input	
// confidentiality
// kite

// Result
// Encrypted text: glsntcfsetiotezv
// Decrypted text: confidentialityz

#include <bits/stdc++.h>
using namespace std;
string ans="";

void toLowerCase(string plain, int plen){
	int i;
	for (i = 0; i < plen; i++) {
		if (plain[i] > 64 && plain[i] < 91)
			plain[i] += 32;
	}
}

int removeSpaces(string plain, int plen){
	int i, count = 0;
	for (i = 0; i < plen; i++)
		if (plain[i] != ' ')
			plain[count++] = plain[i];
	plain[count] = '\0';
	return count;
}

void generateKeyTable(string key, int klen, char keyT[5][5]){
	int i, j, k;

	int dicty[26] = { 0 };
	for (i = 0; i < klen; i++) {
		if (key[i] != 'j')
			dicty[key[i] - 97] = 2;
	}

	dicty['j' - 97] = 1;

	i = 0;
	j = 0;

	for (k = 0; k < klen; k++) {
		if (dicty[key[k] - 97] == 2) {
			dicty[key[k] - 97] -= 1;
			keyT[i][j] = key[k];
			j++;
			if (j == 5) {
				i++;
				j = 0;
			}
		}
	}

	for (k = 0; k < 26; k++) {
		if (dicty[k] == 0) {
			keyT[i][j] = (char)(k + 97);
			j++;
			if (j == 5) {
				i++;
				j = 0;
			}
		}
	}
}

void search(char keyT[5][5], char a, char b, int arr[]){
	int i, j;

	if (a == 'j') a = 'i';
	else if (b == 'j') b = 'i';

	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			if (keyT[i][j] == a) {
				arr[0] = i;
				arr[1] = j;
			}
			else if (keyT[i][j] == b) {
				arr[2] = i;
				arr[3] = j;
			}
		}
	}
}

int mod5(int a) { return (a % 5); }

//ENCRYPT
void encrypt(string str, char keyT[5][5], int plen){
	int i, a[4];

	for (i = 0; i < plen; i += 2) {

		search(keyT, str[i], str[i + 1], a);

		if (a[0] == a[2]) {    // same row
			ans += keyT[a[0]][mod5(a[1] + 1)];
			ans += keyT[a[0]][mod5(a[3] + 1)];
		}
		else if (a[1] == a[3]) {   //same col
			ans+= keyT[mod5(a[0] + 1)][a[1]];
			ans+= keyT[mod5(a[2] + 1)][a[1]];
		}
		else {  //box
			ans+= keyT[a[0]][a[3]];
			ans+= keyT[a[2]][a[1]];
		}
	}
}

void encryptByPlayfairCipher(string str, string key){
	int plen, klen;
    char keyT[5][5];

	// Key
	klen = key.size();
	klen = removeSpaces(key, klen);
	toLowerCase(key, klen);

	// Plaintext
	plen = str.size();
	toLowerCase(str, plen);
	
	generateKeyTable(key, klen, keyT);

	encrypt(str, keyT, plen);
}

//DECRYPT
void decrypt(string str, char keyT[5][5], int plen){
	int i, a[4];

	for (i = 0; i < plen; i += 2) {

		search(keyT, str[i], str[i + 1], a);

		if (a[0] == a[2]) {
			ans += keyT[a[0]][mod5(a[1] - 1)];
			ans += keyT[a[0]][mod5(a[3] - 1)];
		}
		else if (a[1] == a[3]) {
			ans+= keyT[mod5(a[0] - 1)][a[1]];
			ans+= keyT[mod5(a[2] - 1)][a[1]];
		}
		else {
			ans+= keyT[a[0]][a[3]];
			ans+= keyT[a[2]][a[1]];
		}
	}
}

void decryptByPlayfairCipher(string str, string key){
	int plen, klen;
    char keyT[5][5];

	// Key
	klen = key.size();
	klen = removeSpaces(key, klen);
	toLowerCase(key, klen);

	// Plaintext
	plen = str.size();
	toLowerCase(str, plen);
	
	generateKeyTable(key, klen, keyT);

	decrypt(str, keyT, plen);
}

int main(){
	string str, key;

	cin>>str;
	cin>>key;
	
	if(str.size()%2!=0){
	    str+='z';
	}

	encryptByPlayfairCipher(str, key);
	cout<<"Encrypted text: "<<ans<<endl;
	
	decryptByPlayfairCipher(str, key);
    cout<<"Decrypted text: "<< str;
	return 0;
}
