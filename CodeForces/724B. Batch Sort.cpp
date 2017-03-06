#include <iostream>
#include <vector>

using namespace std;

int main() {
	int r, c, count;
	bool flag;
	cin >> r >> c;

	vector<vector<int> > arr(r);

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			int tmp;
			cin >> tmp;
			arr[i].push_back(tmp);
		}
	}

	for (int n = 0; n < c; n++) {
		for (int m = n; m < c; m++) {
			for (int k = 0; k < r; k++) {
				int tmp = arr[k][n];
				arr[k][n] = arr[k][m];
				arr[k][m] = tmp;
			}

			for (int i = 0; i < r; i++) {
				count = 0;

				for (int j = 0; j < c; j++) {
					if (arr[i][j] != j + 1) {
						count++;
					}
				}

				if (count > 2) {
					flag = false;
					break;
				}
				else {
					flag = true;
				}
			}

			if (flag) {
				cout << "YES" << endl;
				return 0;
			}

			for (int k = 0; k < r; k++) {
				int tmp = arr[k][n];
				arr[k][n] = arr[k][m];
				arr[k][m] = tmp;
			}
		}
	}

	cout << "NO" << endl;

	return 0;
}
