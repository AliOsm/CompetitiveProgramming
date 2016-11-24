#include <iostream>
#include <string>

using namespace std;

int main() {
	string s, res, tmp;
	bool flag;

	while (cin >> s) {
		flag = true;
		res = tmp = "";

		for (int i = 0, len = s.length(); i < len; i++) {
			if (s[i] == '[') {
				if(flag) res = tmp + res;
				else res += tmp;
				flag = true;
				tmp = "";
				continue;
			}

			if (s[i] == ']') {
				if (flag) res = tmp + res;
				else res += tmp;
				flag = false;
				tmp = "";
				continue;
			}

			tmp += s[i];
		}

		if (flag) res = tmp + res;
		else res += tmp;

		cout << res << endl;
	}

	return 0;
}
