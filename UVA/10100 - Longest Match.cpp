#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <memory.h>
#include <algorithm>
#include <iomanip>

using namespace std;

int const N = 1001;
int dp[N][N];
string s, tmp;
vector<string> s1, s2;

int rec(int i = 0, int j = 0) {
	if(i == (int)s1.size() || j == (int)s2.size())
		return 0;

	int &ret = dp[i][j];
	if(ret != -1) return ret;
	ret = 0;

	if(s1[i] == s2[j])
		return ret = rec(i + 1, j + 1) + 1;

	return ret = max(rec(i + 1, j), rec(i, j + 1));
}

int main() {
	for(int cnt = 1; getline(cin, s); ++cnt) {
		s1.clear();
		s2.clear();

		if(s == "") {
			getline(cin, s);
			cout << setw(2) << cnt << ". Blank!" << endl;
			continue;
		}

		s += ' ';
		tmp = "";
		for(int i = 0; i < (int)s.length(); ++i) {
			if(isalpha(s[i]) || isdigit(s[i])) {
				tmp += s[i];
			} else {
				if(tmp != "")
					s1.push_back(tmp);
				tmp = "";
			}
		}

		getline(cin, s);
		if(s == "") {
			cout << setw(2) << cnt << ". Blank!" << endl;
			continue;
		}

		s += ' ';
		tmp = "";
		for(int i = 0; i < (int)s.length(); ++i) {
			if(isalpha(s[i]) || isdigit(s[i])) {
				tmp += s[i];
			} else {
				if(tmp != "")
					s2.push_back(tmp);
				tmp = "";
			}
		}

		memset(dp, -1, sizeof dp);
		cout << setw(2) << cnt << ". Length of longest match: " << rec() << endl;
	}

	return 0;
}

