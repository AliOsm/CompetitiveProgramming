#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	int a, b, c, d;
	while(cin >> a >> b >> c >> d && a != 0 && b != 0 && c != 0 && d != 0) {
		if(a > b)
			swap(a, b);

		if(c > d)
			swap(c, d);

		cout << min(abs(a - d), abs(b - c)) << ' ' << min(abs(a - d), abs(b - c)) << endl;
	}

	return 0;
}

