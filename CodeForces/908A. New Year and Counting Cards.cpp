#include <bits/stdc++.h>

using namespace std;

int n, m;

int main() {
	string s;
	cin >> s;

	int res = 0;
	for(int i = 0; i < s.length(); ++i)
		if(s[i] == 'a' || s[i] == 'i' || s[i] == 'e' || s[i] == 'o' || s[i] == 'u' || (isdigit(s[i]) && ((s[i] - '0') & 1)))
			++res;

	cout << res << endl;

	return 0;
}
