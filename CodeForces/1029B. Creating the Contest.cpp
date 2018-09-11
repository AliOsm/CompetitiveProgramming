/*
  Idea:
    - Using cumulative sum we can determine the maximum
      number of consequtive elements that form the answer.
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 2e5 + 1;
int n, a[N];
bool ck[N];

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i)
    scanf("%d", a + i);

  for(int i = 1; i < n; ++i)
    ck[i] = a[i] <= 2 * a[i - 1];

  int res = 0;
  for(int i = 0; i < n; ++i) {
    int j = i;
    while(ck[j] == 1)
      ++j;

    if(j != i) {
      res = max(res, j - i);
      i = j;
      --i;
    }
  }

  printf("%d\n", res + 1);

  return 0;
}
