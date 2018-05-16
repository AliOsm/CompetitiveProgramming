#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;

	if(n == 1) {
		cout << 1 << endl;
	} else if(n % 2 == 0) {
		cout << n - (n / 2 - 1) << endl;
	} else {
		cout << n - (n / 2) << endl;
	}

  return 0;
}
