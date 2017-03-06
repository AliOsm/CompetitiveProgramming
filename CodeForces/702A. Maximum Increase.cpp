#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int n, count = 0;
	priority_queue<int> q;

	cin >> n;

	vector<int> arr(n);

	for(int i = 0; i < n; i++) {
		cin >> arr[i];

		if(i == 0) {
			count++;
		} else if(arr[i-1] < arr[i]) {
			count++;
		} else {
			q.push(count);
			count = 1;
		}
	}

	if(count) {
		q.push(count);
	}

	cout << q.top() << endl;

	return 0;
}
