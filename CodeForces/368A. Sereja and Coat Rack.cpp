#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> arr;

int main() {
	int n, d;
	cin >> n >> d;
	
	arr.resize(n);
	for(int i = 0; i < n; i++) cin >> arr[i];
	sort(arr.begin(), arr.end());
	
	int m;
	cin >> m;
	
	int total = 0;
	if(m <= n)
	    for(int i = 0; i < m; i++) total += arr[i];
	else {
	    for(int i = 0; i < n; i++, m--) total += arr[i];
	    total -= d * m;
	}
	
	cout << total << endl;

	return 0;
}
