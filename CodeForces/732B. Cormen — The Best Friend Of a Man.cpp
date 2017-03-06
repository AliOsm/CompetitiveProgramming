#include <iostream>

using namespace std;

int arr[501];

int main() {
	long long n, k, counter = 0;
	cin >> n >> k;

	for (int i = 0; i < n; i++) cin >> arr[i];

	for (int i = 0; i < n - 1; i++)
		if (arr[i] + arr[i + 1] < k) {
			counter += k - (arr[i] + arr[i + 1]);
			arr[i + 1] += k - (arr[i] + arr[i + 1]);
		}

	cout << counter << endl;
	for (int i = 0; i < n; i++) cout << arr[i] << ' ';
	cout << endl;

	return 0;
}
