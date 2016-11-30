#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int in[26];
vector<int> g[26];
queue<int> q;
string s[100];

int main() {
	int n, x, y;
	cin >> n;

	for (int i = 0; i < n; i++) cin >> s[i];

	for (int i = 0; i + 1 < n; i++) {
		int mn = min(s[i].length(), s[i + 1].length());

		x = -1;
		y = -1;
		for (int j = 0; j < mn; j++)
			if (s[i][j] != s[i + 1][j]) {
				x = s[i][j];
				y = s[i + 1][j];
				break;
			}

		if (x == -1) {
			if (s[i].length() > s[i + 1].length()) {
				cout << "Impossible" << endl;
				return 0;
			}

			continue;
		}

		x -= 'a';
		y -= 'a';

		g[x].push_back(y);
		in[y]++;
	}

	for (int i = 0; i < 26; i++)
		if (in[i] == 0)
			q.push(i);

	string res = "";

	while (!q.empty()) {
		int fr = q.front();
		q.pop();
		res += char(fr + 'a');

		for (int i = 0; i < g[fr].size(); i++)
			if (--in[g[fr][i]] == 0)
				q.push(g[fr][i]);
	}

	if(res.length() == 26)
		cout << res << endl;
	else
		cout << "Impossible" << endl;

	return 0;
}
