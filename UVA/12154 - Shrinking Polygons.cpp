/*
  Idea:
    - Observation: if there is `n` points lies on circumference of a circle
      and the distance between point number `1` and point number `n` across
      the other points is `x`, then if we change the locations of the other
      points the distance between the first and the last points will be the
      same.
    - Observation: the side length of the regular polygon should equal to
      the sum of lengths between the points divided by the number of points
      in the regular polygon.
    - Using the above observations we can brute force to find the minimum
      solution.
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 1e4 + 1;
int n, a[N], sum;
set<int> st;

int main() {
  while(scanf("%d", &n) && n != 0) {
    sum = 0;
    st.clear();

    for(int i = 0; i < n; ++i) {
      scanf("%d", a + i);
      sum += a[i];
      st.insert(sum);
    }

    int res = -1;
    for(int i = n, side; i >= 3 && res == -1; --i) {
      if(sum % i == 0) {
        side = sum / i;

        for(int j = 0, s = 0; s <= side; s += a[j], ++j) {
          bool ok = true;
          for(int k = s; k < sum && ok; k += side)
            ok &= st.count(k);
          if(ok) {
            res = n - i;
            break;
          }
        }
      }
    }

    printf("%d\n", res);
  }

  return 0;
}
