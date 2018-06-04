#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 2;
int t, n, m, lst, cnt, tmp, a[N];
multiset<int> mst;
multiset<int>::iterator it;

int main() {
  bool bl = false;

  scanf("%d", &t);
  while(t-- != 0) {
  	if(bl)
  		puts("");

  	scanf("%d %d", &n, &m);
  	for(int i = 1; i <= n; ++i)
  		scanf("%d", a + i);

  	cnt = 0;
  	lst = 1;
  	mst.clear();
  	mst.insert(-1000000000);
  	it = mst.begin();

  	for(int k = 1; m-- != 0; ++k) {
  		scanf("%d", &tmp);
  		for(int i = lst; i <= tmp; ++i) {
  			mst.insert(a[i]);
  			if(a[i] < *it)
  				--it;
  		}
  		lst = tmp + 1;

  		while(it != mst.end() && cnt < k)
  			++it, ++cnt;

  		printf("%d\n", *it);
  	}

  	bl = true;
  }

  return 0;
}
