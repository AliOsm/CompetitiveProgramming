/*
  Idea:
    - Greedy.
    - Observation: `x` can be always 1000000000.
    - If a[i] equal to a[i + 1] then I will be in the same cell and by definition
      it is incorrect so print NO.
    - If the subtraction resulf between any two consequtive elements greater
      than 1 store it in a set, if there is two or results then print NO.
    - If there is no two consequtive elements with subtraction result greater
      than 1, then print 1000000000 1000000000, because it will be a range of
      numbers v, v + 1, v + 2, ..., u.
    - If there is only one subtraction result then check if this result can
      be the answer for the `y`.
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 2e5 + 1;
int n, a[N];
set<int> diff;

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i)
  	scanf("%d", a + i);

  for(int i = 0; i < n - 1; ++i) {
  	if(a[i] == a[i + 1]) {
  		puts("NO");
  		return 0;
  	}

  	if(a[i] != a[i + 1] + 1 && a[i] != a[i + 1] - 1)
  		diff.insert(abs(a[i] - a[i + 1]));
  }

  if(diff.empty())
  	puts("YES\n1000000000 1000000000");
  else if(diff.size() != 1)
  	puts("NO");
  else {
  	int y = *(diff.begin());

  	for(int i = 0, cur, nxt, row1, row2; i < n - 1; ++i) {
  		cur = a[i], nxt = a[i + 1];
  		row1 = ceil(1.0 * cur / y), row2 = ceil(1.0 * nxt / y);

  		if(cur + y == nxt || cur - y == nxt)
  			continue;

  		if(cur - 1 == nxt && row1 == row2)
  			continue;

  		if(cur + 1 == nxt && row1 == row2)
  			continue;

  		puts("NO");
  		return 0;
  	}

  	puts("YES");
  	printf("1000000000 %d\n", y);
  }

  return 0;
}
