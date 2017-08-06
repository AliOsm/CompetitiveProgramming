#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

int main() {
	int n;
	string s;
	cin >> n;
	cin.ignore();
	getline(cin, s);
	s += ' ';

	int res = 0, capitals = 0;
	for(int i = 0; i < n + 1; ++i)
		if(s[i] == ' ') {
			res = max(res, capitals);
			capitals = 0;
		} else if(isupper(s[i]))
			capitals += 1;

	cout << res << endl;

	return 0;
}
