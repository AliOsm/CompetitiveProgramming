#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

int main() {
	double a, b, c;
	cin >> a >> b >> c;

	cout << max(a, max(b, c)) << " eh o maior" << endl;

	return 0;
}
