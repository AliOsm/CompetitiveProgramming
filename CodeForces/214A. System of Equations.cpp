#include <iostream>

using namespace std;

int main() {
	int x, y, c = 0;

	cin >> x >> y;

	if (x <= y) {
		for (int i = 0; i <= x; i++)
			for (int j = 0; j <= x; j++)
				if ((i * i) + j == x && i + (j * j) == y)
					c++;
	} else {
		for (int i = 0; i <= y; i++)
			for (int j = 0; j <= y; j++)
				if ((i * i) + j == x && i + (j * j) == y)
					c++;
	}

	cout << c << endl;

	return 0;
}
