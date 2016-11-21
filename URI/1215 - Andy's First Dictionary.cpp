#include <iostream>
#include <set>
#include <string>
#include <cstdlib>

using namespace std;

set<string> se;

int main() {
	string s;
	
	while(cin >> s) {
		s += ' ';
		string tmp = "";

		for(int i = 0, len = s.length(); i < len; i++) {
			if(!isalpha(s[i])) {
				while(i < len && !isalpha(s[i]))
					i++;
				i--;
				
				if(tmp != "")
					se.insert(tmp);
				tmp = "";
			} else {
				tmp += tolower(s[i]);
			}
		}
	}

	for(set<string>::iterator it = se.begin(); it != se.end(); it++) {
		cout << *it << endl;
	}

	return 0;
}
