#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

vector<vector<int> > arr;
vector<bool> vis;

void DFS(int i) {
	if(vis[i] == true)
		return;

	vis[i] = true;

	for(int j = 0; j < arr[i].size(); j++) {
		DFS(arr[i][j]);
	}
}

int main() {
	int n, m;
	cin >> n >> m;

	if(m != n - 1) {
		cout << "NO" << endl;
		return 0;
	}

	arr.resize(n);
	vis.resize(n);

	for(int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		--a; --b;

		arr[a].push_back(b);
		arr[b].push_back(a);
	}

	DFS(0);

	for(int i = 0; i < n; i++) {
		if(!vis[i]) {
			cout << "NO" << endl;
			return 0;
		}
	}

	cout << "YES" << endl;

	return 0;
}
