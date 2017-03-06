#include <iostream>
#include <string>

using namespace std;

int main() {
	int n;
	cin >> n;
	string s = "";
	for(int i = 1; i < n; i++) i % 2 == 0 ? s += "I love that " : s += "I hate that ";
	n % 2 == 0 ? s += "I love it" : s += "I hate it";
	cout << s << endl;

	return 0;
}
