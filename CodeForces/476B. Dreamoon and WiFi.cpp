#include <bits/stdc++.h>

using namespace std;

int f, s, q;

int rec(int at, int po) {
	if(at == q)
		return po == f;
	return rec(at + 1, po + 1) + rec(at + 1, po - 1);
}

int main() {
	string s1, s2;
	cin >> s1 >> s2;

	for(int i = 0; i < (int)s1.length(); ++i)
		f += s1[i] == '+' ? 1 : -1;
	for(int i = 0; i < (int)s2.length(); ++i)
		if(s2[i] == '?')
			++q;
		else
			s += s2[i] == '+' ? 1 : -1;

	int res = rec(0, s);

	cout << fixed << setprecision(12) << res / pow(2, q) << endl;

	return 0;
}

