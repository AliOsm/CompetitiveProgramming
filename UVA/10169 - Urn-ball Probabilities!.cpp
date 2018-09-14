/*
  Idea:
    - Probability!
    - There is no problem when calculating the first part of the output,
      All you need ot do is calculating the probability of each step
      and add them all together.
    - To count the number of zeros you need to track the ratio of getting
      two red balls all the time and in the final result the number of
      zeros is how many times you multiply the ratio by 10 and is less
      than 1.
    - To prevent TLE verdict do the previous work using as pre-calculation.
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 1e6 + 1;
int n, cnt[N];
double p[N];

int main() {
  double r = 1;
  p[0] = cnt[0] = 0;
  for(int i = 1; i < N; ++i) {
    p[i] = (1 - p[i - 1]) * 1.0 / i * 1.0 / (1.0 + i);
    if(i > 1)
      p[i] += p[i - 1];

    r *= 1.0 / i;
    r *= 1.0 / (1.0 + i);

    cnt[i] = cnt[i - 1];
    while(r < 1)
      ++cnt[i], r *= 10;
  }

  while(scanf("%d", &n) != EOF)
    printf("%0.6lf %d\n", p[n], cnt[n] - 1);

  return 0;
}
