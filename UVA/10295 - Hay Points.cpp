#include <iostream>
#include <map>
#include <string>

using namespace std;

map<string, int> ma;

int main() {
	string s;
	int n, m, tmp;
	cin >> n >> m;

	for(int i = 0; i < n; i++) {
		cin >> s >> tmp;
		ma[s] = tmp;
	}

	while(m--) {
		s = "";
		int c = 0;
		while(s != ".") {
			cin >> s;
			c += ma[s];
		}
		cout << c << endl;
	}

	return 0;
}
