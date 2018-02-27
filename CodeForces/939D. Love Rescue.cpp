#include <bits/stdc++.h>

using namespace std;

int n;
string s1, s2;
vector<vector<int> > g;
bool vis[26];
queue<int> q;

bool BFS(int src, int dest) {
	memset(vis, false, sizeof vis);
	while(!q.empty())
		q.pop();

	q.push(src);

	while(!q.empty()) {
		int fr = q.front();
		q.pop();

		if(fr == dest)
			return true;

		if(vis[fr])
			continue;
		vis[fr] = true;

		for(int i = 0; i < g[fr].size(); ++i)
			if(!vis[g[fr][i]])
				q.push(g[fr][i]);
	}

	return false;
}

int main() {
	g.resize(26);

	cin >> n >> s1 >> s2;

	int res = 0;
	vector<pair<char, char> > st;
	for(int i = 0; i < n; ++i) {
		if(!BFS(s1[i] - 'a', s2[i] - 'a')) {
			st.push_back(make_pair(s1[i], s2[i]));
			++res;
			g[s1[i] - 'a'].push_back(s2[i] - 'a');
			g[s2[i] - 'a'].push_back(s1[i] - 'a');
		}
	}

	cout << res << endl;
	for(int i = 0; i < st.size(); ++i)
		cout << st[i].first << ' ' << st[i].second << endl;

	return 0;
}

