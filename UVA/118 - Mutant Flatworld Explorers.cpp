#include <bits/stdc++.h>

using namespace std;

int const N = 51;
int n, m, ix, iy, len;
char id, s[101];
set<pair<int, int> > st;

int main() {
	scanf("%d %d", &n, &m);

	while(scanf("%d %d %c", &ix, &iy, &id) != EOF) {
		scanf("%s", s);
		len = strlen(s);

		bool ok = true;
		for(int i = 0; i < len; ++i) {
			if(s[i] == 'R') {
				if(id == 'N')
					id = 'E';
				else if(id == 'E')
					id = 'S';
				else if(id == 'S')
					id = 'W';
				else
					id = 'N';
			} else if(s[i] == 'L') {
				if(id == 'N')
					id = 'W';
				else if(id == 'E')
					id = 'N';
				else if(id == 'S')
					id = 'E';
				else
					id = 'S';
			} else {
				if(id == 'N')
					++iy;
				if(id == 'E')
					++ix;
				if(id == 'S')
					--iy;
				if(id == 'W')
					--ix;

				if(ix < 0 || ix > n || iy < 0 || iy > m) {
					if(id == 'N')
						--iy;
					if(id == 'E')
						--ix;
					if(id == 'S')
						++iy;
					if(id == 'W')
						++ix;

					if(st.find(make_pair(ix, iy)) != st.end())
						continue;

					printf("%d %d %c LOST\n", ix, iy, id);
					st.insert(make_pair(ix, iy));

					ok = false;
					break;
				}
			}
		}

		if(ok)
			printf("%d %d %c\n", ix, iy, id);
	}

	return 0;
}
