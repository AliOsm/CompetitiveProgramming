#include <iostream>
#include <vector>
#include <string>

using namespace std;

void main() {
	int n, counter = 0;
	vector<string> arr;
	string s;

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> s;
		arr.push_back(s);
	}

	for (int i = 0; i <= n - 1; i++) {
		for (int j = 0; j <= n - 1; j++) {
			if (arr[i][j] == 'C') {
				
				for (int x = j + 1; x <= n - 1; x++) {
					if (arr[i][j] == arr[i][x]) {
						counter++;
					}
				}

				for (int x = i + 1; x <= n - 1; x++) {
					if (arr[i][j] == arr[x][j])
						counter++;
				}

			}
		}
	}

	cout << counter << endl;
}
