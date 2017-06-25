#include <iostream>
#include <string>
#include <memory.h>
#include <algorithm>
#include <vector>

using namespace std;

int const N = 3001;
int dp[N][N];
vector<string> t1, t2, sol;

int calc(int i, int j) {
	if(i == (int)t1.size() || j == t2.size())
		return 0;

	int &res = dp[i][j];
	if(res != -1) return res;
	res = 0;

	if(t1[i] == t2[j])
		return res = calc(i + 1, j + 1) + 1;

	return res = max(calc(i + 1, j), calc(i, j + 1));
}

void path(int i, int j) {
	if(i == (int)t1.size() || j == (int)t2.size())
		return;

	if(t1[i] == t2[j]) {
		sol.push_back(t1[i]);
		path(i + 1, j + 1);
		return;
	}

	if(calc(i, j) == calc(i + 1, j))
		path(i + 1, j);
	else
		path(i, j + 1);
}

int main() {
	string tmp;

	while(cin >> tmp) {
		t1.clear();
		t2.clear();

		do {
			t1.push_back(tmp);
		} while(cin >> tmp && tmp != "#");

		while(cin >> tmp && tmp != "#") {
			t2.push_back(tmp);
		}

		memset(dp, -1, sizeof dp);
		calc(0, 0);

		sol.clear();
		path(0, 0);

		for(int i = 0; i < (int)sol.size(); ++i) {
			if(i) cout << ' ';
			cout << sol[i];
		}
		cout << endl;
	}

	return 0;
}

