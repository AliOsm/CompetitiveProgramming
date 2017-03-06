#include <iostream>
#include <vector>

using namespace std;

int main() {
	int i, t, total = 0, tmp;
	cin >> i >> t;

	while(i--) {
		cin >> tmp;

		if (tmp + t <= 5)
			total++;
	}

	if (total < 3) {
		cout << 0 << endl;
		return 0;
	}

	cout << total / 3 << endl;
	return 0;
}
