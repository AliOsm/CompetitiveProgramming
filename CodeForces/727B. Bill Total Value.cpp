#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	vector<string> nums;
	long long a = 0, b = 0;
	string s;
	cin >> s;

	for (int i = 0, sLen = s.length(); i < sLen; i++) {
		if (!isdigit(s[i])) {
			while (!isdigit(s[i++])) {}
			i -= 2;
		}
		else {
			string tmp = "";
			int dots = 0;

			while (isdigit(s[i]) || s[i] == '.') {
				tmp += s[i++];
				if (s[i] == '.') dots++;
			}

			if (dots > 1) {
				for (int j = 0, tmpLen = tmp.length(); j < tmpLen && dots > 1; j++)
					if (tmp[j] == '.') {
						tmp.erase(j++, 1);
						dots--;
					}

				int dotLoc = tmp.find('.') + 1;
				if (tmp.length() - dotLoc == 3)
					tmp.erase(--dotLoc, 1);
			}
			else {
				int dotLoc = tmp.find('.') + 1;
				if (dotLoc && tmp.length() - dotLoc == 3)
					tmp.erase(--dotLoc, 1);
			}

			nums.push_back(tmp);
		}
	}

	for (int i = 0, numsLen = nums.size(); i < numsLen; i++) {
		stringstream ss(nums[i]);
		int tmp1 = 0, tmp3 = 0;
		char tmp2;

		ss >> tmp1 >> tmp2 >> tmp3;
		
		a += tmp1;
		b += tmp3;
	}

	while (b > 99) {
		b -= 100;
		a++;
	}

	vector<int> res;
	while (a != 0) {
		int fthreeDigit = a % 1000;
		res.push_back(fthreeDigit);
		a /= 1000;
	}

	if (res.size()) {
		reverse(res.begin(), res.end());
		for (int i = 0; i < res.size() - 1; i++) {
			if (res[i] == 0) {
				cout << "000.";
			}
			else {
				if (i != 0 && res[i] < 100)
					cout << 0;

				if (i != 0 && res[i] < 10)
					cout << 0;

				cout << res[i] << ".";
			}
		}

		if (res[res.size() - 1] == 0) {
			cout << "000";
		}
		else {
			if (res.size() != 1 && res[res.size() - 1] < 100)
				cout << 0;

			if (res.size() != 1 && res[res.size() - 1] < 10)
				cout << 0;

			cout << res[res.size() - 1];
		}
	}
	else {
		cout << a;
	}

	if(b)
		if (b < 10)
			cout << ".0" << b;
		else
			cout << '.' << b;

	cout << endl;

	return 0;
}
