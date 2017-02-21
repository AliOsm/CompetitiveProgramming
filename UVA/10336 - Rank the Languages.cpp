#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;

int n, m;
bool vis[10001][10001];
vector<string> g;
pair<int, char> freq[26];

int dx[] = { 1, 0, -1, 0};
int dy[] = { 0, 1, 0, -1};

void DFS(int i, int j) {
	vis[i][j] = true;
	
	for(int k = 0; k < 4; k++) {
		int ni = i + dx[k];
		int nj = j + dy[k];
		
		if(ni < n && ni >= 0 && nj < m && nj >= 0 && !vis[ni][nj] && g[i][j] == g[ni][nj])
			DFS(ni, nj);
	}
}

int main() {
	int t;
	cin >> t;
	
	for(int c = 1; t--; c++) {
		cin >> n >> m;
		
		memset(vis, false, sizeof vis);
		g.clear();
		g.resize(n);
		
		for(int i = 0; i < 26; i++) {
		    freq[i].first = 0;
		    freq[i].second = i;
		}
		
		for(int i = 0; i < n; i++)
			cin >> g[i];
		
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				if(!vis[i][j]) {
					freq[g[i][j] - 'a'].first++;
					DFS(i, j);
				}
		
		sort(freq, freq + 26);
		
		cout << "World #" << c << endl;
		
		for(int i = 25; i >= 0;)
		    if(freq[i].first) {
    		    int j = i, k;
    		    while(freq[j].first == freq[i].first) j--;
    		    k = j;

    		    j++;
    		    while(j <= i) {
    		        cout << char(freq[j].second + 'a') << ": " << freq[j].first << endl;
    		        j++;
    		    }
    		    
    		    i = k;
		    } else break;
	}
   
   return 0;
}
