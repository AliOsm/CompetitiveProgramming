#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;

int main() {
	string tmp1, tmp2, tmp;
	int x, y;
	cin >> x >> y;

	map<string, string> hash;

	for (int i = 0; i < y; i++) {
		cin >> tmp;
		cin >> hash[tmp];
	}

	for (int i = 0; i < x; i++) {
		cin >> tmp;

		tmp1 = tmp;
		tmp2 = hash[tmp];

		if (tmp1.length() <= tmp2.length())
			cout << tmp1 << ' ';
		else
			cout << tmp2 << ' ';
	}
	
	return 0;
}
