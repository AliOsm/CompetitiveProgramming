#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
	int n;
	cin >> n;

	string res = "", tmp;
	stringstream s;

	for (int i = 1; i <= n; i++) {
		s.clear();
		s << i;
		s >> tmp;
		res += tmp;
	}

	cout << res[n - 1] << endl;

	return 0;
}
