/*
  Idea:
    - Greedy.
    - If we have one row from the hexagon of sides 1, 1, 2, 1, then we can split it into 3 triangles.
     ─
    / \
    ─ ─
    - If we try to do the same thing with row has sides 2, 1, 3, 1, the we can split it into 5 triangles, which is the summation of the sides
      2 and 3.
    - From the previous point we can calculate each row alone and add it to the result.
*/

#include <bits/stdc++.h>

using namespace std;

int a[6];

int main() {
  for(int i = 0; i < 6; ++i)
    scanf("%d", a + i);
  
  int res = 0;

  int l = a[0], r = a[0] + min(a[1], a[5]);
  for(int i = l; i < r; ++i)
    res += i + i + 1;

  l = a[3], r = a[3] + min(a[4], a[2]);
  for(int i = l; i < r; ++i)
    res += i + i + 1;

  l = r, r = abs(a[1] - a[5]);
  for(int i = 0; i < r; ++i)
    res += 2 * l;
  
  printf("%d\n", res);

  return 0;
}
