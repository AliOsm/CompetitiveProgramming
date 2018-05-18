/*
  Idea:
    - Sort the array M1, M2, ..., Mn
    - For each element in the array subtract the number of elements less than it
    - In this way we reserve a number for each jar
    - The result will be the multiplication of the elements of the array under MOD
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 1e2 + 1, MOD = 1e9 + 7;
int t, n, a[N];

int main() {
  int kase = 1;
  scanf("%d", &t);
  while(t-- != 0) {
    printf("Case %d: ", kase++);
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
      scanf("%d", a + i);
    sort(a, a + n);

    int sol = 1;
    for(int i = 0; i < n; ++i)
      sol = 1ll * sol * (a[i] - i) % MOD;
    printf("%d\n", sol);
  }

  return 0;
}
