#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;

	string res = "";
	for(int i = 0; i < s.length(); ++i) {
		if(s[i] == 'a' || s[i] == 'o' || s[i] == 'u' || s[i] == 'e' || s[i] == 'i' || s[i] == 'y') {
			int tmp = i;
			while(i+1 < s.length() && (s[i+1] == 'a' || s[i+1] == 'o' || s[i+1] == 'u' || s[i+1] == 'e' || s[i+1] == 'i' || s[i+1] == 'y')) {
				++i;
			}
			res += s[tmp];
		} else {
			res += s[i];
		}
	}

	cout << res << endl;

	return 0;
}
