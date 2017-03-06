#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	string s;
	cin >> s;
	s = "a" + s;

	int counter = 0;

	for (int i = 0, len = s.length() - 1; i < len; i++) {
		int tmp1, tmp2, counter1 = 0, counter2 = 0;

		tmp1 = (int)s[i] - 'a';
		tmp2 = (int)s[i + 1] - 'a';
		while (tmp1 != tmp2) {
			tmp1--;
			if (tmp1 < 0)
				tmp1 = 25;

			counter1++;
		}

		tmp1 = (int)s[i] - 'a';
		tmp2 = (int)s[i + 1] - 'a';
		while (tmp1 != tmp2) {
			if (tmp1 >= 25)
				tmp1 = -1;
			tmp1++;

			counter2++;
		}

		counter += min(counter1, counter2);
	}

	cout << counter << endl;

	return 0;
}
