#include <iostream>
#include <string>

using namespace std;

typedef long long ll;

int main() {
	string s;
	cin >> s;

	int f = 0, b = 0;
	for(int i = 0; i < 3; ++i)
		f += s[i] - '0';
	for(int i = 3; i < 6; ++i)
		b += s[i] - '0';

	if(f == b) {
		cout << 0 << endl;
		return 0;
	}

	int res = 1e9;
	for(int i = 0; i < 10; ++i)
		for(int j = 0; j < 10; ++j)
			for(int k = 0; k < 10; ++k)
				for(int l = 0; l < 10; ++l)
					for(int m = 0; m < 10; ++m)
						for(int n = 0; n < 10; ++n)
							if(i + j + k == l + m + n)
								res = min(res, (s[0] - '0' != i) + (s[1] - '0' != j) + (s[2] - '0' != k) +
												(s[3] - '0' != l) + (s[4] - '0' != m) + (s[5] - '0' != n));

	cout << res << endl;

	return 0;
}

