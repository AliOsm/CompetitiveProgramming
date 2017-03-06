#include <iostream>
#include <string>

using namespace std;

int countLucky(string tmp) {
	int c = 0;

	for (int i = 0; i < tmp.length(); i++) {
		if (tmp[i] == '4' || tmp[i] == '7')
			c++;
	}

	return c;
}

int main() {
	int x, y, c = 0;
	string tmp;
	cin >> x >> y;

	while (x--) {
		cin >> tmp;

		if (countLucky(tmp) <= y)
			c++;
	}

	cout << c << endl;

	return 0;
}
