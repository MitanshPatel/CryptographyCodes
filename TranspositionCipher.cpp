// #include <iostream>
// #include <stdlib.h>
// #include <string.h>
// #include <cmath>
// using namespace std;
// typedef struct
// {
//     int Key;
//     char Value;
// } KeyValuePair;
// int rows = 3;
// int compare(const void *first, const void *second)
// {
//     return ((KeyValuePair *)first)->Value - ((KeyValuePair *)second)->Value;
// }

// char **Create2DArray(int rowCount, int colCount)
// {
//     char **rArray = (char **)malloc(sizeof(char *) * rowCount);

//     for (int i = 0; i < rowCount; i++)
//     {
//         rArray[i] = (char *)malloc(sizeof(char) * colCount);
//     }

//     return rArray;
// }

// char *PadRight(char *str, int max, char padChar)
// {
//     int strLen = strlen(str);
//     char *output = (char *)malloc(sizeof(char *) * max);

//     if (strLen < max)
//     {
//         //   int padLen = max - strLen;
//         for (int i = 0; i < max; ++i)
//             output[i] = i < strLen ? str[i] : padChar;
//     }

//     output[max] = '\0';
//     return output;
// }

// int *GetShiftIndexes(char *key)
// {
//     int keyLength = strlen(key);
//     int *indexes = (int *)malloc(sizeof(int) * keyLength);
//     KeyValuePair *sortedKey = (KeyValuePair *)malloc(sizeof(KeyValuePair) * keyLength);
//     int i;

//     for (i = 0; i < keyLength; ++i)
//         sortedKey[i] = {i, key[i]};

//     qsort(sortedKey, keyLength, sizeof(KeyValuePair), compare);
//     i = 0;

//     for (int i = 0; i < keyLength; ++i)
//         indexes[sortedKey[i].Key] = i;

//     return indexes;
// }

// char *Encipher(char *input, char *key, char padChar)
// {
//     int totalChars = strlen(input);
//     int keyLength = strlen(key);
//     input = (totalChars % keyLength == 0) ? input : PadRight(input, totalChars - (totalChars % keyLength) + keyLength, padChar);
//     totalChars = strlen(input);
//     char *output = (char *)malloc(sizeof(char) * totalChars);
//     int totalColumns = keyLength;
//     int totalRows = (int)ceil((double)totalChars / totalColumns);
//     char **rowChars = Create2DArray(totalRows, totalColumns);
//     char **colChars = Create2DArray(totalColumns, totalRows);
//     char **sortedColChars = Create2DArray(totalColumns, totalRows);
//     int currentRow, currentColumn, i, j;
//     int *shiftIndexes = GetShiftIndexes(key);

//     for (i = 0; i < totalChars; ++i)
//     {
//         currentRow = i / totalColumns;
//         currentColumn = i % totalColumns;
//         rowChars[currentRow][currentColumn] = input[i];
//     }

//     for (i = 0; i < totalRows; ++i)
//         for (j = 0; j < totalColumns; ++j)
//             colChars[j][i] = rowChars[i][j];

//     for (i = 0; i < totalColumns; ++i)
//         for (j = 0; j < totalRows; ++j)
//             sortedColChars[shiftIndexes[i]][j] = colChars[i][j];

//     for (i = 0; i < totalChars; ++i)
//     {
//         currentRow = i / totalRows;
//         currentColumn = i % totalRows;
//         output[i] = sortedColChars[currentRow][currentColumn];
//     }

//     output[totalChars] = '\0';
//     output[rows] = ' ';
//     return output;
// }

// char *Decipher(char *input, char *key)
// {
//     int keyLength = strlen(key);
//     int totalChars = strlen(input);
//     char *output = (char *)malloc(sizeof(char *) * totalChars);
//     int totalColumns = (int)ceil((double)totalChars / keyLength);
//     int totalRows = keyLength;
//     char **rowChars = Create2DArray(totalRows, totalColumns);
//     char **colChars = Create2DArray(totalColumns, totalRows);
//     char **unsortedColChars = Create2DArray(totalColumns, totalRows);
//     int currentRow, currentColumn, i, j;
//     int *shiftIndexes = GetShiftIndexes(key);

//     for (i = 0; i < totalChars; ++i)
//     {
//         currentRow = i / totalColumns;
//         currentColumn = i % totalColumns;
//         rowChars[currentRow][currentColumn] = input[i];
//     }

//     for (i = 0; i < totalRows; ++i)
//         for (j = 0; j < totalColumns; ++j)
//             colChars[j][i] = rowChars[i][j];

//     for (i = 0; i < totalColumns; ++i)
//         for (j = 0; j < totalRows; ++j)
//             unsortedColChars[i][j] = colChars[i][shiftIndexes[j]];

//     for (i = 0; i < totalChars; ++i)
//     {
//         currentRow = i / totalRows;
//         currentColumn = i % totalRows;
//         output[i] = unsortedColChars[currentRow][currentColumn];
//     }

//     output[totalChars] = '\0';
//     return output;
// }
// int main()
// {
//     char text[100] = "kill corona virus";
//     char key[100] = "healthy";
//     char *cipherText = Encipher(text, key, '_');
//     char *plainText = Decipher(cipherText, key);
//     cout << "Encrypted text: " << cipherText << endl;
//     cout << "Decrypted text: " << plainText;
//     return 0;
// }

// CPP program for illustrating
// Columnar Transposition Cipher
#include<bits/stdc++.h>
using namespace std;

// Key for Columnar Transposition
string const key = "heal"; 
map<int,int> keyMap;

void setPermutationOrder(){ 
	// Add the permutation order into map 
	for(int i=0; i < key.length(); i++){  //h->0, e->1, a->2, l->3.   After sort it becomes, a->2, e->1 .....
		keyMap[key[i]] = i;
	}
}

// Encryption 
string encryptMessage(string msg)
{
	int row,col,j;
	string cipher = "";
	
	/* calculate column of the matrix*/
	col = key.length(); 
	
	/* calculate Maximum row of the matrix*/
	row = msg.length()/col; 
	
	if (msg.length() % col)
		row += 1;

	char matrix[row][col];
    int k=0;
	for (int i=0; i < row; i++){
		for (int j=0; j<col; j++){
			if(k >= msg.length()){
				matrix[i][j] = '_';
			}
			else{
				matrix[i][j] = msg[k];
			}
			k++;
		}
	}

	for (auto ii = keyMap.begin(); ii!=keyMap.end(); ++ii){  // ascending wise so a->2,e->1,h->0,l->3
		j=ii->second;
		// getting cipher text from matrix column wise using permuted key
		for (int i=0; i<row; i++){
			cipher += matrix[i][j];
		}
	}
	return cipher;
}

// Decryption 
string decryptMessage(string cipher)
{
	/* calculate row and column for cipher Matrix */
	int col = key.length();

	int row = cipher.length()/col;
	char cipherMat[row][col];

	/* add character into matrix column wise */
    int k=0;
	for (int j=0; j<col; j++){
		for (int i=0; i<row; i++){
			cipherMat[i][j] = cipher[k];
            k++;
        }
    }
	/* update the order of key for decryption */
	int index = 0;
	for( auto ii=keyMap.begin(); ii!=keyMap.end(); ++ii)  // so that, a->0, e->1, h->2, l->3.
		ii->second = index++;

	/* Arrange the matrix column wise according 
	to permutation order by adding into new matrix */
	char decCipher[row][col];
	auto ii=keyMap.begin();
	k = 0;
	for (int l=0; l<key.size(); l++){
		int j = keyMap[key[l]];
		for (int i=0; i<row; i++){
			decCipher[i][k]=cipherMat[i][j];
		}
        k++;
	}

	/* getting Message using matrix */
	string msg = "";
	for (int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			msg += decCipher[i][j];
		}
	}
	return msg;
}

// Driver Program
int main(void)
{
	/* message */
	string msg = "Apple is fresh "; 

	setPermutationOrder();
	
	// Calling encryption function
	string cipher = encryptMessage(msg);
	cout << "Encrypted Message: " << cipher << endl;
	
	// Calling Decryption function
	cout << "Decrypted Message: " << decryptMessage(cipher) << endl;

	return 0;
}
