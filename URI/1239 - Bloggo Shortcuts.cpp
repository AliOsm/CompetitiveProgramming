#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    
    while(getline(cin, s)) {
    	bool fi = true;
    	bool bi = true;
    	
    	string res = "";
    	for(int i = 0, len = s.length(); i < len; i++) {
    		if(s[i] == '_')
    			if(fi) {
    				res += "<i>";
    				fi = !fi;
    			} else {
    				res += "</i>";
    				fi = !fi;
    			}
    		else if(s[i] == '*')
    			if(bi) {
    				res += "<b>";
    				bi = !bi;
    			} else {
    				res += "</b>";
    				bi = !bi;
    			}
    		else res += s[i];
    	}
    	cout << res << endl;
    }
    
    return 0;
}
