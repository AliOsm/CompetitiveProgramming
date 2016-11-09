#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> D, E;

int main() {
	freopen("input.txt", "r", stdin);

	int n;

	while (cin >> n) {
		for (int i = 0; i < n; i++) {
			int iTmp;
			char cTmp;
			cin >> iTmp >> cTmp;
			if (cTmp == 'D')
				D.push_back(iTmp);
			else
				E.push_back(iTmp);
		}

		int c = 0;
		sort(D.begin(), D.end());
		sort(E.begin(), E.end());

		for (int j = 0, len1 = D.size(); j < len1; j++)
			for (int k = 0, len2 = E.size(); k < len2; k++)
				if (D[j] == E[k]) {
					c++;
					D.erase(D.begin() + j);
					E.erase(E.begin() + k);
					len1--;
					len2--;
					j--;
					k--;
					break;
				}

		D.clear();
		E.clear();
		cout << c << endl;
	}

	return 0;
}
