#include <stdio.h>
#include <string>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);

	char s[9];
	scanf("%s", s);

	if(n == 6) {
		puts("espeon");
	}

	if(n == 7) {
		string ls[6] = {"jolteon", "flareon", "umbreon", "leafeon", "glaceon", "sylveon"};

		for(int i = 0; i < 6; ++i) {
			bool ok = true;
			for(int j = 0; j < 6; ++j)
				if(s[j] != '.' && s[j] != ls[i][j]) {
					ok = false;
					break;
				}
			if(ok) {
				puts(ls[i].c_str());
				break;
			}
		}
	}

	if(n == 8) {
		puts("vaporeon");
	}

	return 0;
}
