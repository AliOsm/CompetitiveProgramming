#include <bits/stdc++.h>

using namespace std;

int main() {
	int a, b;
	cin >> a >> b;

	if(a > b)
		swap(a, b);

	bool t = true;
	int res = 0, aa = 1, bb = 1;
	while(a < b) {
		if(t) {
			++a;
			res += aa;
			++aa;
			t = !t;
		} else {
			--b;
			res += bb;
			++bb;
			t = !t;
		}
	}

	cout << res << endl;

	return 0;
}