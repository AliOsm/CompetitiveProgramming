#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
    	string s;
    	cin >> s;
    	
    	if(s.length() == 3)
    		if(s[0] == 'o' && s[1] == 'n')
    			cout << 1 << endl;
    		else if(s[1] == 'n' && s[2] == 'e')
    			cout << 1 << endl;
    		else if(s[0] == 'o' && s[2] == 'e')
    			cout << 1 << endl;
    		else if(s[0] == 'o' && (s[1] != 'w' || s[2] != 'o'))
    			cout << 1 << endl;
    		else if(s[1] == 'n' && (s[0] != 't' || s[2] != 'o'))
    			cout << 1 << endl;
    		else if(s[2] == 'e' && (s[0] != 't' || s[1] != 'w'))
    			cout << 1 << endl;
    		else
    			cout << 2 << endl;
    	else
    		cout << 3 << endl;
    }
    
    return 0;
}
