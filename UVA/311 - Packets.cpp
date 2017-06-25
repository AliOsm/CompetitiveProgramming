#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int b6, b5, b4, b3, b2, b1, res;
	while(cin >> b1 >> b2 >> b3 >> b4 >> b5 >> b6 &&
		  (b6 != 0 || b5 != 0 || b4 != 0 || b3 != 0 || b2 != 0 || b1 != 0)) {
		res = b6 + b5 + b4;

		b1 -= 11 * b5;
		b2 -= 5 * b4;

		res += ceil(1.0 * b3 / 4);

		if(b3 % 4 == 1) {
			b1 -= 7;
			b2 -= 5;
		} else if(b3 % 4 == 2) {
			b1 -= 6;
			b2 -= 3;
		} else if(b3 % 4 == 3) {
			b1 -= 5;
			b2 -= 1;
		}

		if(b2 > 0) {
			res += ceil(1.0 * b2 / 9);
			b2 -= ceil(1.0 * b2 / 9) * 9;
		}

		if(b2 < 0)
			b1 += b2 * 4;

		if(b1 > 0)
			res += ceil(1.0 * b1 / 36);

		cout << res << endl;
	}

	return 0;
}

