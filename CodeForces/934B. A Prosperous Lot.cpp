#include <bits/stdc++.h>

using namespace std;

int main() {
	int k;
	cin >> k;

	if(k >= 37) {
		cout << -1 << endl;
		return 0;
	}

	while(k > 1) {
		putchar('8');
		k -= 2;
	}

	if(k == 1)
		putchar('4');

	puts("");

	return 0;
}
