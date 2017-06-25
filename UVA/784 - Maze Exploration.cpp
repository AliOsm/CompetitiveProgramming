#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> grid;
string s, underscores;
int x, y;

bool allUnderscores(string &s) {
	for(int i = 0; i < (int)s.length(); ++i)
		if(s[i] != '_')
			return false;
	underscores = s;
	return true;
}

void DFS(int i, int j) {
	for(int k = 0; k < 4; ++k) {
		int nx, ny;
		nx = i + dx[k];
		ny = j + dy[k];

		if(nx >= 0 && nx < (int)grid.size() && ny >= 0 && ny < (int)grid[nx].length() && grid[nx][ny] == ' ') {
			grid[nx][ny] = '#';
			DFS(nx, ny);
		}
	}
}

int main() {
	int t;
	cin >> t;

	cin.ignore();
	while(t-- != 0) {
		grid.clear();
		for(int i = 0; getline(cin, s) && !allUnderscores(s); ++i) {
			grid.push_back(s);

			if(s.find('*') != string::npos) {
				x = i;
				y = s.find('*');
			}
		}

		DFS(x, y);
		grid[x][y] = '#';

		for(int i = 0; i < (int)grid.size(); ++i)
			cout << grid[i] << endl;
		cout << underscores << endl;
	}

	return 0;
}

