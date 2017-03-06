#include <iostream>
#include <cstdlib>

using namespace std;

void main() {
	int n, t;
	long double res;

	cin >> n >> t;

	res = pow(1.000000011, t) * n;

	cout << res << endl;
}
