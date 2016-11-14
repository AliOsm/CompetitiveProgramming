#include <iostream>
#include <string>
#include <cstdlib>
 
using namespace std;

int main() { 
	string s;
	
	while(getline(cin, s)) {
		bool f = true;
		
		for(int i = 0, len = s.length(); i < len; i++)
			if(isalpha(s[i]))
				if(f) {
					s[i] = toupper(s[i]);
					f = !f;
				} else {
					s[i] = tolower(s[i]);
					f = !f;
				}
		
		cout << s << endl;
	}

    return 0; 
} 
