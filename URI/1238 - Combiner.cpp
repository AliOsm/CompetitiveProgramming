#include <iostream>
#include <algorithm>
#include <string>
 
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		string s1, s2;
		cin >> s1 >> s2;
		string res = "";
		
		for(int i = 0, len = max(s1.length(), s2.length()); i < len; i++) {
			if(i < s1.length() && s1[i] != ' ')
				res += s1[i];
			
			if(i < s2.length() && s2[i] != ' ')
				res += s2[i];
		}
		
		cout << res << endl;
	}

    return 0; 
} 
