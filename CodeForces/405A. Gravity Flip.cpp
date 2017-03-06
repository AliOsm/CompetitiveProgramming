#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int t;
	cin >> t;

	vector<int> arr(t);

	for (int i = 0; i < t; i++) {
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());

	for (int i = 0; i < t; i++) {
		cout << arr[i] << ' ';
	}

	cout << endl;


	return 0;
}
