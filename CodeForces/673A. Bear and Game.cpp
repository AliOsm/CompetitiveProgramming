#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;

int main() {
	int t, tmp;
	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> tmp;
		arr.push_back(tmp);
	}

	if (arr[0] - 1 >= 15) {
		cout << 15 << endl;
		return 0;
	}

	if (t == 1) {
		if (arr[0] >= 16)
			cout << 15 << endl;
		else if (arr[0] <= 15)
			cout << arr[0] + 15 << endl;

		return 0;
	}

	for (int i = 0; i < t - 1; i++) {
		if (arr[i + 1] - arr[i] > 15) {
			cout << arr[i] + 15 << endl;
			return 0;
		}
	}

	if (arr.size() >= 2 && arr[arr.size() - 1] - arr[arr.size() - 2] > 15) {
		cout << arr[arr.size() - 2] + 15 << endl;
		return 0;
	}

	if (arr.size() >= 2 && 90 - arr[arr.size() - 1] > 15) {
		cout << arr[arr.size() - 1] + 15 << endl;
		return 0;
	}

	cout << 90 << endl;

	return 0;
}
