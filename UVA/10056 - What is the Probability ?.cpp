/*
  Idea:
    - Calculate the probability of player `i` with the game from the
      first time, second time, third time, ..., 100000th time.
*/

#include <bits/stdc++.h>

using namespace std;

int s, n, i;
double p, q;

int main() {
  scanf("%d", &s);
  while(s-- != 0) {
    scanf("%d %lf %d", &n, &p, &i);
    q = (1.0 - p);

    double c1 = pow(q, i - 1) * p, c2 = pow(q, n), c3 = c2;
    double res = c1;
    for(int j = 1; j < 100000; ++j)
      res += c2 * c1, c2 *= c3;
    
    printf("%0.4lf\n", res);
  }

  return 0;
}
