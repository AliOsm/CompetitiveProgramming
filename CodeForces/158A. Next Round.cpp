#include <iostream>

using namespace std;

int arr[101];

int main() {
	int n, k, c = 0;
	cin >> n >> k;

	for (int i = 0; i < n; i++) cin >> arr[i];

	for (int i = 0; i < n; i++)
		if(arr[i] > 0 && arr[i] >= arr[k-1]) c++;

	cout << c << endl;

	return 0;
}
