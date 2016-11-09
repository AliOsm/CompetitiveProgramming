#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
    	int n, c = 0;
    	cin >> n;
    	
    	for(int i = 0; n--; i++) {
    		string s;
    		cin >> s;
    		
    		for(int j = 0, len = s.length(); j < len; j++)
    			c += (s[j] - 'A') + i + j;
    	}
    	
    	cout << c << endl;
    }
    
    return 0;
}
