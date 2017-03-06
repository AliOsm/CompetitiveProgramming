#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, m;
	cin >> n;
	m = n / 2;

	vector<pair<int, int>> cards(n);
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;

		cards[i].first = x;
		cards[i].second = i + 1;
	}

	sort(cards.begin(), cards.end());

	int j = n - 1;
	for(int i = 0; i < m; i++) {
		cout << cards[i].second << " " << cards[j].second << endl;
		j--;
	}

	return 0;
}
