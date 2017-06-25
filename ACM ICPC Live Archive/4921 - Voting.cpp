#include <iostream>
#include <string>

using namespace std;

string s;

int main() {
	int y, n, p, a;
	while(cin >> s && s != "#") {
		y = n = p = a = 0;
		for(int i = 0; i < (int)s.length(); i++) {
			if(s[i] == 'Y') ++y;
			if(s[i] == 'N') ++n;
			if(s[i] == 'P') ++p;
			if(s[i] == 'A') ++a;
		}

		if(a >= ((int)s.length() / 2 + (s.length() % 2 == 1))) puts("need quorum");
		else if(y > n) puts("yes");
		else if(n > y) puts("no");
		else puts("tie");
	}

	return 0;
}

