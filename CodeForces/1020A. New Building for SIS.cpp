/*
  Idea:
    - If the towers are the same then the answer is the absolute
      difference between the floors.
    - If the towers are not the same then try to move from the
      first tower to the second using the minimum number of steps.
    - The minimum number of steps is to move first from the
      current floor to points `a` or `b` (if the current floor
      is not inside them), then move to the second tower and move
      from the current floor to the target one.
*/

#include <bits/stdc++.h>

using namespace std;

int n, h, a, b, k;

int main() {
  scanf("%d %d %d %d %d", &n, &h, &a, &b, &k);
  for(int i = 0, fa, ta, fb, tb; i < k; ++i) {
    scanf("%d %d %d %d", &ta, &fa, &tb, &fb);
    if(ta == tb)
      printf("%d\n", abs(fa - fb));
    else {
      int res = 0;

      if(fa >= a && fa <= b) {
        res += abs(ta - tb);
        res += abs(fa - fb);
      } else {
        if(abs(fa - a) < abs(fa - b))
          res += abs(fa - a) + abs(ta - tb) + abs(fb - a);
        else
          res += abs(fa - b) + abs(ta - tb) + abs(fb - b);
      }

      printf("%d\n", res);
    }
  }

  return 0;
}
