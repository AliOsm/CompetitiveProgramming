#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    cin.ignore();
    while(t--) {
    	string s;
    	getline(cin, s);
    	
    	int frec[26] = {0};
    	
    	for(int i = 0, len = s.length(); i < len; i++)
    		if(isalpha(s[i])) frec[s[i] - 'a']++;
    		
    	int c = 0;
    	for(int i = 0; i < 26; i++)
    		if(frec[i]) c++;
    		
    	if(c == 26)
    		cout << "frase completa" << endl;
    	else if(c >= 13)
    		cout << "frase quase completa" << endl;
    	else
    		cout << "frase mal elaborada" << endl;
    }
    
    return 0;
}
