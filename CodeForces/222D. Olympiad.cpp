/*
  Idea:
    - Greedly we can choose any element from array `a` and find the smallest element in array `b` which there sums greater than
      or equal to `x`.
    - We can use multiset to tracking the elements of array `b`.
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;
int n, x, a[N];
multiset<int> mst;

int main() {
  scanf("%d %d", &n, &x);
  for(int i = 0; i < n; ++i)
    scanf("%d", a + i);
  for(int i = 0, tmp; i < n; ++i) {
    scanf("%d", &tmp);
    mst.insert(tmp);
  }
  
  sort(a, a + n);

  int worst = 0;
  for(int i = 0; i < n; ++i) {
    int need = x - a[i];
    auto it = mst.lower_bound(need);
    if(it != mst.end()) {
      ++worst;
      mst.erase(it);
    }
  }

  printf("1 %d\n", worst);

  return 0;
}
