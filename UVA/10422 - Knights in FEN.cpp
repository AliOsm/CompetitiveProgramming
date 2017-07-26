#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int dx[] = { 2, -2, 1, -1, 2, -2, 1, -1 };
int dy[] = { 1, -1, 2, -2, -1, 1, -2, 2 };
vector<string> g;
queue<vector<string> > qu;
set<vector<string> > st;

bool check(vector<string> &fr) {
	return fr[0] == "11111" &&
		   fr[1] == "01111" &&
		   fr[2] == "00 11" &&
		   fr[3] == "00001" &&
		   fr[4] == "00000";
}

pair<int, int> findSpace(vector<string> &fr) {
	for(int i = 0; i < 5; ++i)
		for(int j = 0; j < 5; ++j)
			if(fr[i][j] == ' ')
				return make_pair(i, j);
	return make_pair(0, 0);
}

int BFS() {
	while(!qu.empty()) qu.pop();
	st.clear();

	qu.push(g);
	st.insert(g);

	vector<string> fr;
	pair<int, int> space;
	int cost = 0, size;
	while(!qu.empty()) {
		size = qu.size();

		while(size--) {
			fr.clear();
			fr = qu.front();
			qu.pop();

			if(check(fr))
				return cost;

			if(cost > 10)
				return cost;

			space = findSpace(fr);
			for(int i = 0, nx, ny; i < 8; ++i) {
				nx = space.first + dx[i];
				ny = space.second + dy[i];

				if(nx >= 0 && nx < 5 && ny >= 0 && ny < 5) {
					swap(fr[space.first][space.second], fr[nx][ny]);
					if(st.find(fr) == st.end()) {
						qu.push(fr);
						st.insert(fr);
					}
					swap(fr[space.first][space.second], fr[nx][ny]);
				}
			}
		}

		++cost;
	}

	return cost;
}

int main() {
	int t;
	cin >> t;
	cin.ignore();
	while(t-- != 0) {
		g.clear();
		g.resize(5);
		for(int i = 0; i < 5; ++i)
			getline(cin, g[i]);

		int res = BFS();
		if(res == 11) cout << "Unsolvable in less than 11 move(s)." << endl;
		else cout << "Solvable in " << res << " move(s)." << endl;
	}

	return 0;
}

