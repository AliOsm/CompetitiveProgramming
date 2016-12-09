#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <memory.h>

using namespace std;

const int N = 21;
int n, arr1[N], arr2[N], dp[N], cur_index[N];

int calc(int i) {
	if (i == n) return 0;

	int &res = dp[i];
	if (res != -1) return res;

	res = 0;
	for (int j = i + 1; j < n; j++)
		for (int k = cur_index[arr2[i]] + 1; k < n; k++)
			if (arr2[j] == arr1[k])
				res = max(res, calc(j) + 1);

	return res;
}

int main() {
	string s;
	int res, tmp;

	cin >> n;
	for (int i = 0; i < n; i++) {
	    cin >> tmp;
	    arr1[tmp - 1] = i;
	    cur_index[arr1[i]] = i;
	}

	cin.ignore();
	while (getline(cin, s)) {
	  stringstream ss(s);
		for (int i = 0; i < n; i++) {
		    ss >> tmp;
		    arr2[tmp - 1] = i;
		}
		memset(dp, -1, sizeof dp);
        
		res = 0;
		for (int i = 0; i < n; i++)
			res = max(res, calc(i) + 1);

		cout << res << endl;
	}

	return 0;
}
