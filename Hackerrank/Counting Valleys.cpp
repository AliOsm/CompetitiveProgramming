#include <iostream>
#include <string>

using namespace std;

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;

	int sea = 0, res = 0;
	bool start = false;
	for(int i = 0; i < (int)s.length(); ++i) {
		if(s[i] == 'U')
			++sea;
		else
			--sea;

		if(sea < 0)
			start = true;
		else {
			if(start)
				++res;
			start = false;
		}
	}

	cout << res << endl;

    return 0;
}

