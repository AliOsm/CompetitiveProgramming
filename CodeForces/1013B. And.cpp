/*
  Idea:
    - Greedy.
    - There is 4 cases:
      1- check if there is 2 elements in the array equal to
         each other, then the answer is 0.
      2- check if the anding operation with any element
         exists in the array in another index, then the answer is 1.
      3- check if you anded each element in the array with `x`
         is there two elements equal to each other? then the answer is 2.
      4- otherwise the answer if -1.
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;
int n, x, a[N], fr[N];

int main() {
  scanf("%d %d", &n, &x);
  for(int i = 0; i < n; ++i)
    scanf("%d", a + i), ++fr[a[i]];

  for(int i = 0; i < N; ++i)
    if(fr[i] > 1) {
      puts("0");
      return 0;
    }

  for(int i = 0; i < n; ++i)
    if((a[i] & x) != a[i] && fr[a[i] & x] > 0) {
      puts("1");
      return 0;
    }

  memset(fr, 0, sizeof fr);
  for(int i = 0; i < n; ++i)
    ++fr[a[i] & x];

  for(int i = 0; i < N; ++i)
    if(fr[i] > 1) {
      puts("2");
      return 0;
    }

  puts("-1");

  return 0;
}
