#include <iostream>
#include <string>
#include <vector>
#include <memory.h>

using namespace std;

vector<vector<int> > g;
bool vis[26];

void DFS(int n) {
	vis[n] = 1;
	for (int i = 0; i < g[n].size(); i++)
		if(!vis[g[n][i]])
			DFS(g[n][i]);
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		g.clear();
		memset(vis, false, 26);

		char tmp;
		cin >> tmp;
		int end = tmp - 'A' + 1;
		g.resize(end);

		for (int i = 0; i < end; i++) g[i].push_back(i);

		string s;
		cin.ignore();
		while (getline(cin, s) && s != "") {
			int a = s[0] - 'A';
			int b = s[1] - 'A';
			g[a].push_back(b);
			g[b].push_back(a);
		}

		int c = 0;
		for (int i = 0; i < g.size(); i++)
			for(int j = 0; j < g[i].size(); j++)
				if (!vis[g[i][j]]) {
					c++;
					DFS(g[i][j]);
				}

		cout << c << endl;
		if (t) cout << endl;
	}

	return 0;
}
