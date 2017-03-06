#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;

long long a, b;
vector<int> arr;

int main() {
	int a, b;
	cin >> a >> b;

	arr.push_back(b);

	while (a != b) {
		if (b % 2 == 0) {
			b /= 2;
			arr.push_back(b);
		}
		else if ((b - 1) % 10 == 0 && b - 1 != 0) {
			b = (b - 1) / 10;
			arr.push_back(b);
		}
		else {
			cout << "NO" << endl;
			return 0;
		}
	}

	cout << "YES" << endl;
	cout << arr.size() << endl;

	reverse(arr.begin(), arr.end());

	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << ' ';
	}

	cout << endl;

	return 0;
}
