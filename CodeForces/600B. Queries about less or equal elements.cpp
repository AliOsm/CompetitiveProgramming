#include <iostream>
#include <algorithm>

using namespace std;

const int N = 2 * 1e5;
int arr[N] = {0};

int main() {
	int n, m;
	cin >> n >> m;

	for(int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr+n);

	for(int i = 0; i < m; i++) {
		int tmp;
		cin >> tmp;
		cout << upper_bound(arr, arr+n, tmp) - arr << endl;
	}

	return 0;
}
