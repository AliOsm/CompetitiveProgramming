#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;

const int N = 8;

queue<pair<int, int> > q;
bool vis[N][N];
int dx[] = { -1, -1, -2, -2, 2, 2, 1, 1 };
int dy[] = { -2, 2, -1, 1, -1, 1, -2, 2 };

map<pair<int, int>, pair<int, int> > parent;
vector<pair<int, int> > sol;

string src, des;

void path(int ex, int ey) {
	sol.clear();
	pair<int, int> at = make_pair(ex, ey);

	while (at.first != -1 && at.second != -1) {
		sol.push_back(at);
		at = parent[at];
	}

	reverse(sol.begin(), sol.end());

	for (int i = 0, len = sol.size(); i < len; i++) {
		cout << (char)(sol[i].first + 97) << sol[i].second + 1;
		if (i + 1 != len) cout << " -> ";
	}

	cout << "\n\n";
}

int BFS(int sx, int sy, int ex, int ey) {
	int cost = 0, size;

	while (!q.empty()) q.pop();
	memset(vis, false, sizeof vis);
	parent.clear();
	
	q.push(make_pair(sx, sy));
	vis[sx][sy] = true;
	parent[make_pair(sx, sy)] = make_pair(-1, -1);

	while (!q.empty() && (++cost) && (size = q.size()))
		while (size--) {
			pair<int, int> fr = q.front();
			q.pop();

			for (int i = 0; i < N; i++) {
				pair<int, int> cur = make_pair(fr.first + dx[i], fr.second + dy[i]);

				if (cur.first >= 0 && cur.first < N && cur.second >= 0 && cur.second < N && !vis[cur.first][cur.second]) {
					parent[cur] = fr;
					if (ex == cur.first && ey == cur.second) return cost;

					q.push(cur);
					vis[cur.first][cur.second] = true;
				}
			}
		}
}

int main() {
	freopen("input.txt", "r", stdin);
	
	while (cin >> src >> des) {
		if (src == des) {
			cout << "To get from " << src << " to " << des << " takes 0 knight moves." << endl;
			cout << "Nothing!\n\n";
			continue;
		}

		int sx = src[0] - 'a';
		int sy = src[1] - '0' - 1;
		int ex = des[0] - 'a';
		int ey = des[1] - '0' - 1;

		cout << "To get from " << src << " to " << des << " takes " << BFS(sx, sy, ex, ey) << " knight moves." << endl;
		path(ex, ey);
	}

	return 0;
}
