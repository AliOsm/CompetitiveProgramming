#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;

int n, m, cnt;
bool vis[51][51];
vector<string> g;
vector<pair<int, char> > freq;

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

bool cmp(pair<int, char> a, pair<int, char> b) {
	if(a.first!= b.first)return a.first>b.first;
    else return a.second<b.second;
}

void DFS(int i, int j) {
	vis[i][j] = true;
	cnt++;
	
	for(int k = 0; k < 4; k++) {
		int ni = i + dx[k];
		int nj = j + dy[k];
		
		if(ni < n && ni >= 0 && nj < m && nj >= 0 && !vis[ni][nj] && g[i][j] == g[ni][nj])
			DFS(ni, nj);
	}
}

int main() {
	for(int c = 1; cin >> n >> m && n && m; c++) {
		g.clear();
		g.resize(n);
		freq.clear();
		memset(vis, false, sizeof vis);
		
		for(int i = 0; i < n; i++) cin >> g[i];
		
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				if(!vis[i][j] && g[i][j] != '.') {
					cnt = 0;
					DFS(i, j);
					freq.push_back(make_pair(cnt, g[i][j]));
				}
		
		sort(freq.begin(), freq.end(), cmp);
		
		cout << "Problem " << c << ':' << endl;
		for(int i = 0; i < (int)freq.size(); i++)
			cout << freq[i].second << ' ' << freq[i].first << endl;
	}
   
  return 0;
}
