#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
	int a, b;
	cin >> a >> b;

	int n;
	cin >> n;

	vector<double> arr(n);

	for(int i = 0; i < n; i++) {
		double x, y, v;
		cin >> x >> y >> v;

		double d = sqrt(pow((x - a), 2.0) + pow((y - b), 2.0));
		arr[i] = d / v;
	}

	sort(arr.begin(), arr.end());
	cout << fixed << setprecision(20) << arr[0] << endl;

	return 0;
}
