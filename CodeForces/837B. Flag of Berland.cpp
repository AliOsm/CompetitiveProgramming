#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> flag;

int main() {
	int n, m;
	cin >> n >> m;

	flag.resize(n);
	for(int i = 0; i < n; ++i)
		cin >> flag[i];

	if(n % 3 != 0 && m % 3 != 0) {
		cout << "NO" << endl;
		return 0;
	}

	bool ok;

	if(n % 3 == 0) {
		ok = true;
		int strip = n / 3;
		char s1 = flag[0][0];
		char s2 = flag[strip][0];
		char s3 = flag[(2 * strip)][0];

		for(int i = 0; i < strip; ++i)
			for(int j = 0; j < m; ++j)
				if(flag[i][j] != s1)
					ok = false;
		for(int i = strip; i < 2 * strip; ++i)
			for(int j = 0; j < m; ++j)
				if(flag[i][j] != s2)
					ok = false;
		for(int i = 2 * strip; i < 3 * strip; ++i)
			for(int j = 0; j < m; ++j)
				if(flag[i][j] != s3)
					ok = false;

		if(ok && s1 != s2 && s1 != s3 && s2 != s3) {
			cout << "YES" << endl;
			return 0;
		}
	}

	if(m % 3 == 0) {
		ok = true;
		int strip = m / 3;
		char s1 = flag[0][0];
		char s2 = flag[0][strip];
		char s3 = flag[0][(2 * strip)];

		for(int i = 0; i < n; ++i)
			for(int j = 0; j < strip; ++j)
				if(flag[i][j] != s1)
					ok = false;
		for(int i = 0; i < n; ++i)
			for(int j = strip; j < 2 * strip; ++j)
				if(flag[i][j] != s2)
					ok = false;
		for(int i = 0; i < n; ++i)
			for(int j = 2 * strip; j < 3 * strip; ++j)
				if(flag[i][j] != s3)
					ok = false;

		if(ok && s1 != s2 && s1 != s3 && s2 != s3) {
			cout << "YES" << endl;
			return 0;
		}
	}

	cout << "NO" << endl;

	return 0;
}
