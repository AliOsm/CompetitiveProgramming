#include <bits/stdc++.h>

using namespace std;

int main() {
	int f = 1, s = 1;
	vector<int> fib;
	fib.push_back(f);
	fib.push_back(s);
	while(s < 2000) {
		int tmp = s;
		s = f + s;
		f = tmp;
		fib.push_back(s);
	}

	int n;
	cin >> n;

	string res = "";
	for(int i = 1; i <= n; ++i) {
		if(binary_search(fib.begin(), fib.end(), i))
			res += 'O';
		else
			res += 'o';
	}

	cout << res << endl;

	return 0;
}
