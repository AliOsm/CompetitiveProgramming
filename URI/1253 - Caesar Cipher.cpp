#include <iostream>
#include <string>
 
using namespace std;

const string LANGUAGE_LETTERS = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main() { 
	int t;
    cin >> t;
    
    string s;
    int key;

    while (t-- && cin >> s >> key) {
        for (int i = 0, j, len = s.length(); i < len; i++)
            if ((s[i] - 'A') - key < 0)
                s[i] = LANGUAGE_LETTERS[((s[i] - 'A') - key + 26) % 26]; 
            else
                s[i] = LANGUAGE_LETTERS[((s[i] - 'A') - key) % 26];

        cout << s << endl; 
    } 
 
 
    return 0; 
} 
