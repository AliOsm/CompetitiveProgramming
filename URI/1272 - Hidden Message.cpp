#include <iostream>
#include <string>

using namespace std;

int main() {
	int t;
	cin >> t;
	
	cin.ignore();
	while(t--) {
		string s, res = "";
		getline(cin, s);
		
		for(int i = 0, len = s.length(); i < len; i++)
			if(s[i] != ' ') {
				res += s[i];
				
				while(i < len && s[i] != ' ') i++;
			}
			
		cout << res << endl;
	}
	
	return 0;
}
