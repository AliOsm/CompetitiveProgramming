#include <stdio.h>
#include <algorithm>
#include <cmath>

using namespace std;

set<pair<pair<int, int>, pair<int, int> > > all;
set<pair<int, int> > st;
set<long long> dist;

int main() {
	bool ok = true;
	for(int i = 0; i < 4; ++i) {
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

		if((x1 != x2 && y1 != y2) || (x1 == y1 && x1 == x2 && x1 == y2 && y1 == x2 && y1 == y2 && x2 == y2))
			ok = false;

		st.insert(make_pair(x1, y1));
		st.insert(make_pair(x2, y2));

		if(x1 <= x2 && y1 <= y2)
			all.insert(make_pair(make_pair(x1, y1), make_pair(x2, y2)));
		else
			all.insert(make_pair(make_pair(x2, y2), make_pair(x1, y1)));
	}

	for(set<pair<int, int> >::iterator it1 = st.begin(); it1 != st.end(); ++it1)
		for(set<pair<int, int> >::iterator it2 = st.begin(); it2 != st.end(); ++it2)
			if(it1 != it2)
				dist.insert(1LL * (it1->first - it2->first) * (it1->first - it2->first) +
							1LL * (it1->second - it2->second) * (it1->second - it2->second));

	if(all.size() != 4 || st.size() != 4 || dist.size() > 3 || !ok) {
		puts("NO");
		return 0;
	}

	long long d[3];
	int i = 0;
	for(set<long long>::iterator it = dist.begin(); it != dist.end(); ++it, ++i)
		d[i] = *it;

	if((dist.size() == 2 && d[0] * d[0] == 0) || (dist.size() == 3 && d[0] * d[1] == 0)) {
		puts("NO");
		return 0;
	}

	int xmn = 1e9 + 10, xmx = -1e9 - 10, ymn = 1e9 + 10, ymx = -1e9 - 10;
	for(set<pair<int, int> >::iterator it = st.begin(); it != st.end(); ++it) {
		xmn = min(xmn, it->first);
		xmx = max(xmx, it->first);
		ymn = min(ymn, it->second);
		ymx = max(ymx, it->second);
	}

	if(st.count(make_pair(xmn, ymn)) && st.count(make_pair(xmn, ymx)) &&
	   st.count(make_pair(xmx, ymn)) && st.count(make_pair(xmx, ymx)))
		puts("YES");
	else
		puts("NO");

	return 0;
}

