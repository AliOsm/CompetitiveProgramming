#include <bits/stdc++.h>

using namespace std;

int t, n, m, k, len, cur, idx, cnt, mx, mn, all[1001][21], votes[21];
bool vis[21], ok;
char s[81];
string tmp;
vector<int> win;
map<int, string> mp;

int main() {
	bool new_line = false;
	scanf("%d", &t);
	while(t-- != 0) {
		if(new_line)
			puts("");

		mp.clear();
		memset(all, 0, sizeof all);
		memset(vis, false, sizeof vis);

		scanf("%d", &n);
		cin.ignore();
		for(int i = 0; i < n; ++i) {
			fgets(s, sizeof s, stdin);
			len = strlen(s);
			s[len - 1] = '\0';
			tmp = s;
			mp[i] = tmp;
		}

		for(int i = 0; fgets(s, sizeof s, stdin); ++i) {
			len = strlen(s);
			s[len - 1] = '\0';
			tmp = s;
			if(tmp == "")
				break;
			stringstream ss(tmp);
			for(int j = 0; ss >> cur; ++j) {
				all[i][j] = --cur;
				k = j;
			}
			m = i;
		}
		++m, ++k;

		idx = -1;
		while(idx == -1) {
			memset(votes, 0, sizeof votes);
			idx = -1;

			mx = 0, mn = 10000;
			for(int i = 0; i < m; ++i)
				for(int j = 0; j < k; ++j)
					if(all[i][j] != -1) {
						++votes[all[i][j]];
						mx = max(mx, votes[all[i][j]]);
						break;
					}

			for(int i = 0; i < n; ++i)
				if(!vis[i])
					mn = min(mn, votes[i]);

			if(mn == 10000)
				mn = 0;

			if(mx > m / 2) {
				for(int i = 0; i < n; ++i)
					if(votes[i] == mx) {
						idx = i;
						break;
					}
				break;
			} else {
				win.clear();
				for(int i = 0; i < n; ++i)
					if(votes[i] == mx)
						win.push_back(i);

				memset(vis, false, sizeof vis);
				for(int i = 0; i < n; ++i)
					if(votes[i] == mn)
						vis[i] = true;
				cnt = 0;
				for(int i = 0; i < m; ++i)
					for(int j = 0; j < k; ++j) {
						if(vis[all[i][j]])
							all[i][j] = -1;

						if(all[i][j] == -1)
							++cnt;
					}

				if(cnt == m * k)
					break;
			}
		}

		if(idx != -1) {
			printf("%s\n", mp[idx].c_str());
		} else {
			for(int i = 0; i < win.size(); ++i)
				printf("%s\n", mp[win[i]].c_str());
		}

		new_line = true;
	}

  return 0;
}
