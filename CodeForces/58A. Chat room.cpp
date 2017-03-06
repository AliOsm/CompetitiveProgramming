#include <iostream>
#include <string>

using namespace std;

int main() {
	string s;
	cin >> s;

	int h = s.find('h'), e = s.find('e', h), l1 = s.find('l', e), l2 = s.find('l', l1 + 1), o = s.find('o', l2);

	if (h < e && h < l1 && h < l2 && h < o && e < l1 && e < l2 && e < o && l1 < l2 && l1 < o && l2 < o && h != -1 && e != -1 && l1 != -1 && l2 != -1 && o != -1)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	return 0;
}
