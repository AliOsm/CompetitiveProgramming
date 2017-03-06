#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int N;
queue<int> solider1;
queue<int> solider2;
vector<pair<queue<int>, queue<int> > > vis;

void BFS() {
	int cost = 0;

	while (solider1.size() != 0 && solider2.size() != 0) {
		int x = solider1.front();
		solider1.pop();

		int y = solider2.front();
		solider2.pop();

		if (x > y) {
			solider1.push(y);
			solider1.push(x);
		}
		else {
			solider2.push(x);
			solider2.push(y);
		}
		
		if(find(vis.begin(), vis.end(), make_pair(solider1, solider2)) == vis.end()) {
			vis.push_back(make_pair(solider1, solider2));
		} else {
			cout << -1 << endl;
			return;
		}

		cost++;
	}

	cout << cost << ' ';

	if (!solider1.empty()) {
		cout << 1 << endl;
	}
	else {
		cout << 2 << endl;
	}
}

int main() {
	cin >> N;
	int tmp;

	cin >> tmp;
	for (int i = 0; i < tmp; i++) {
		int tmp;
		cin >> tmp;
		solider1.push(tmp);
	}

	cin >> tmp;
	for (int i = 0; i < tmp; i++) {
		int tmp;
		cin >> tmp;
		solider2.push(tmp);
	}

	BFS();

	return 0;
}
