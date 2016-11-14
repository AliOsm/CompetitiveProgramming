#include <iostream>
#include <algorithm>
#include <string>
#include <cstdlib>
 
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		bool f = false;
		string s1, s2;
		cin >> s1 >> s2;
		
		if(s2.length() > s1.length()) {
			cout << "nao encaixa" << endl;
			continue;
		}
		
		for(int i = 0, len = s2.length(), j = s1.length() - len; i < len; i++, j++)
			if(s1[j] != s2[i]) {
				cout << "nao encaixa" << endl;
				f = true;
				break;
			}
		
		if(f) continue;
			
		cout << "encaixa" << endl;
	}

    return 0; 
} 
