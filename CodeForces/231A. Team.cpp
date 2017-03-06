#include <iostream>

using namespace std;

int main() {
	int n, c = 0;
	cin >> n;

	while(n--) {
		int p, v, t;
		cin >> p >> v >> t;

		if((p == 1 && v == 1) || (v == 1 && t == 1) || (t == 1 && p == 1))
			c++;
	}

	cout << c << endl;

	return 0;
}
