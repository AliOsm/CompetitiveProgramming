#include <iostream>
#include <string>

using namespace std;

string s;

int main() {
	int t;
	cin >> t;

	cin.ignore();
	while(t-- != 0) {
		getline(cin, s);

		int lst = -1, tmp;
		for(int i = 0; i < (int)s.length(); ++i)
			if(s[i] == 'h') {
				lst = i;
				break;
			}

		if(lst == -1) {
			cout << "NO" << endl;
			continue;
		}

		tmp = lst;

		for(int i = lst + 1; i < (int)s.length(); ++i)
			if(s[i] == 'a') {
				lst = i;
				break;
			}

		if(lst == tmp) {
			cout << "NO" << endl;
			continue;
		}

		tmp = lst;

		for(int i = lst + 1; i < (int)s.length(); ++i)
			if(s[i] == 'c') {
				lst = i;
				break;
			}

		if(lst == tmp) {
			cout << "NO" << endl;
			continue;
		}

		tmp = lst;

		for(int i = lst + 1; i < (int)s.length(); ++i)
			if(s[i] == 'k') {
				lst = i;
				break;
			}

		if(lst == tmp) {
			cout << "NO" << endl;
			continue;
		}

		tmp = lst;

		for(int i = lst + 1; i < (int)s.length(); ++i)
			if(s[i] == 'e') {
				lst = i;
				break;
			}

		if(lst == tmp) {
			cout << "NO" << endl;
			continue;
		}

		tmp = lst;

		for(int i = lst + 1; i < (int)s.length(); ++i)
			if(s[i] == 'r') {
				lst = i;
				break;
			}

		if(lst == tmp) {
			cout << "NO" << endl;
			continue;
		}

		tmp = lst;

		for(int i = lst + 1; i < (int)s.length(); ++i)
			if(s[i] == 'r') {
				lst = i;
				break;
			}

		if(lst == tmp) {
			cout << "NO" << endl;
			continue;
		}

		tmp = lst;

		for(int i = lst + 1; i < (int)s.length(); ++i)
			if(s[i] == 'a') {
				lst = i;
				break;
			}

		if(lst == tmp) {
			cout << "NO" << endl;
			continue;
		}

		tmp = lst;

		for(int i = lst + 1; i < (int)s.length(); ++i)
			if(s[i] == 'n') {
				lst = i;
				break;
			}

		if(lst == tmp) {
			cout << "NO" << endl;
			continue;
		}

		tmp = lst;

		for(int i = lst + 1; i < (int)s.length(); ++i)
			if(s[i] == 'k') {
				lst = i;
				break;
			}

		if(lst == tmp) {
			cout << "NO" << endl;
			continue;
		}

		tmp = lst;

		cout << "YES" << endl;
	}

    return 0;
}

