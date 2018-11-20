/*
  Idea:
    - Try all possible starting values from 1 to `max(a[i])`.
    - This solution work in ~ `20 * 2*10^5`.
    - To figure why, the smallest starting number is 1
      and in each iteration it should be multiplied by 2,
      so in 18 steps it will reach 262144 which is greater than
      the number of elements in the array.
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 2e5 + 1;
int n, a[N], fr[N];
vector<int> all;

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i)
    scanf("%d", a + i), all.push_back(a[i]);

  sort(all.begin(), all.end());
  all.resize(unique(all.begin(), all.end()) - all.begin());
  for(int i = 0; i < n; ++i)
    a[i] = lower_bound(all.begin(), all.end(), a[i]) - all.begin(),
    ++fr[a[i]];
  all.clear();

  for(int i = 0; i < N; ++i)
    if(fr[i] != 0)
      all.push_back(fr[i]);
  sort(all.begin(), all.end());

  int res = 0, tmp, idx, cur;
  for(int i = 1; i <= all.back(); ++i) {
    tmp = 0, idx = -1, cur = i;
    while(true) {
      idx = lower_bound(all.begin() + idx + 1, all.end(), cur) - all.begin();
      if(idx == all.size())
        break;
      tmp += cur;
      cur += cur;
    }
    res = max(res, tmp);
  }
  printf("%d\n", res);

  return 0;
}
