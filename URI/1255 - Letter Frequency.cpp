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
    	
    	int frec[27] = {0};
    	
    	for(int i = 0, len = s.length(); i < len; i++)
    		frec[tolower(s[i]) - 'a']++;
    		
    	int max = frec[0];
    	for(int i = 1; i < 27; i++)
    		if(frec[i] > max)
    			max = frec[i];
    			
    	for(int i = 0; i < 27; i++)
    		if(frec[i] == max)
    			cout << char(i + 97);
    			
    	cout << endl;
    }
    
    return 0;
}
