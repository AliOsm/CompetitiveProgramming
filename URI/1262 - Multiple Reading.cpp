#include <iostream>
#include <string>

using namespace std;

int main() {
	string s;
	int n;
	
    while(cin >> s >> n) {
    	int c = 0;
    	for(int i = 0, len = s.length(); i < len; i++) {
    		if(s[i] == 'W') c++;
    		else {
    			int tmp = n;
    			while(tmp-- && s[i] == 'R') i++;
    			c++;
    			i--;
    		}
    	}
    	cout << c <<endl;
    }
    
    return 0;
}
