#include <bits/stdc++.h>

using namespace std;

int k, n, m, q, cnt;
char s[100001];
string tmp, name;
map<string, map<string, int> > comp;
map<int, map<string, int> > friends, fin;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif

	scanf("%d %d %d %d", &k, &n, &m, &q);

	for(int i = 1; i <= k; ++i)
		friends[i], fin[i];

	for(int i = 0; i < n; ++i)
		scanf("%s", s);

	cin.ignore();
	for(int i = 0; i < m; ++i) {
		fgets(s, sizeof s, stdin);

		for(int i = 0; s[i] != '\0'; ++i)
			if(s[i] == ':' || s[i] == ',')
				s[i] = ' ';
			else if(s[i] == '\n') {
				s[i] = '\0';
				break;
			}

		tmp = s;
		stringstream ss(tmp);
		ss >> name;
		while(ss >> tmp) {
			ss >> cnt;
			comp[name][tmp] = cnt;
		}
	}

	for(int i = 0; i < q; ++i) {
		scanf("%d %s", &cnt, s);
		name = s;
		++friends[cnt][name];

		while(true) {
			bool ok = false;

			for(map<string, map<string, int> >::iterator it1 = comp.begin(); it1 != comp.end(); ++it1) {
				bool can = true;
				
				for(map<string, int>::iterator it2 = it1->second.begin(); it2 != it1->second.end(); ++it2) {
					if(friends[cnt][it2->first] < it2->second) {
						can = false;
						break;
					}
				}

				if(!can)
					continue;

				for(map<string, int>::iterator it2 = it1->second.begin(); it2 != it1->second.end(); ++it2)
					friends[cnt][it2->first] -= it2->second;

				++fin[cnt][it1->first];
			}

			if(!ok)
				break;
		}
	}

	for(map<int, map<string, int> >::iterator it1 = friends.begin(); it1 != friends.end(); ++it1)
		for(map<string, int>::iterator it2 = it1->second.begin(); it2 != it1->second.end(); ++it2)
			if(it2->second > 0)
				fin[it1->first][it2->first] += it2->second;

	for(map<int, map<string, int> >::iterator it1 = fin.begin(); it1 != fin.end(); ++it1) {
		printf("%d\n", int(it1->second.size()));
		for(map<string, int>::iterator it2 = it1->second.begin(); it2 != it1->second.end(); ++it2)
			printf("%s %d\n", it2->first.c_str(), it2->second);
	}

  return 0;
}
