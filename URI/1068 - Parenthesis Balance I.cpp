#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    
    while(cin >> s) {
    	int c = 0;
    	bool f = true;
    	
    	for(int i = 0, len = s.length(); i < len; i++) {
    		if(s[i] == '(')
    			c++;
    		else if(s[i] == ')')
    			c--;
    		
    		if(c < 0) {
    			f = false;
    			break;
    		}		
    	}
    	
    	if(f && c == 0)
    		cout << "correct" << endl;
    	else
    		cout << "incorrect" << endl;
    }
    
    return 0;
}
