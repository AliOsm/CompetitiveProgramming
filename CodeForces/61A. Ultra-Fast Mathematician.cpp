#include <iostream>
#include <string>

using namespace std;

int main() {
	string a, b;

	int sum = 0;
	cin >> a >> b;

	for (int i = 0; i < a.length(); i++) {
		sum = (a[i] - '0') + (b[i] - '0');
		if (sum == 1)
			a[i] = '1';
		else
			a[i] = '0';
	}

	cout << a << endl;

	return 0;
}
