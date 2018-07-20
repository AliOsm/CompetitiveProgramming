/*
  Idea:
    - If the first element does not 1, then print 1.
    - Starting from the first element, set a `mx` variable to 1,
      then for each element after it, if the element greater
      than the `mx + 1` print `mx + 1` and stop, otherwise add
      the current element to `mx` and continue.
    - If there is no solution till the end of the array, then
      print the sum of the array plus 1.
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 1e2 + 1;
int n, t, a[N];

int main() {
  cin >> n;
  for(int i = 0; i < n; ++i)
    cin >> a[i], t += a[i];

  if(a[0] > 1) {
    puts("1");
    return 0;
  }

  int mx = 1;
  for(int i = 1; i < n; ++i) {
    if(a[i] > mx + 1) {
      printf("%d\n", mx + 1);
      return 0;
    }
    mx += a[i];
  }

  printf("%d\n", t + 1);

  return 0;
}
