#include <iostream>
#include <string>

using namespace std;

int main() {
    string s1, s2;
    
    while(getline(cin, s1) && getline(cin, s2)) {
    	if(s1.length() > s2.length()) s1.swap(s2);
    	
    	int res = 0;
    	
    	for(int i = 0, k = 0, len = s1.length(); i < len; i++, k++) {
    		int c = 0;
    		for(int j = 0, len = s2.length(); j < len; j++) {
    			if(s1[k] == s2[j]) {
    				int cc = 1;
    				k++;
    				j++;
    				while(s1[k] == s2[j] && j < len) {
    					cc++;
    					k++;
    					j++;
    				}
    				if(cc > c) c = cc;
    				k = i;
    			}
    		}
    		if(c > res) res = c;
    		k = i;
    	}
    	
    	cout << res << endl;
    }
    
    return 0;
}
