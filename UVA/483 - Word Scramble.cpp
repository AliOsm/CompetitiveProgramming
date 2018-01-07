#include <bits/stdc++.h>

using namespace std;

int main() {
	string line;
	while(getline(cin, line)) {
		stringstream ss(line);

		string cur;
		bool space = false;
		while(ss >> cur) {
			if(space)
				cout << ' ';
			reverse(cur.begin(), cur.end());
			cout << cur;
			space = true;
		}
		cout << endl;
	}

	return 0;
}

