#include <bits/stdc++.h>

using namespace std;

long long a, b, c;

/*
1 b
2 a
3 a
4 b
5 c
6 a
7 c
*/

bool can(long long str, long long mid) {
  long long days[8] = {0};
  for(int i = str; i <= 7; ++i)
    days[i] = 1;
  mid -= (7 - str + 1);
  long long weeks = mid / 7;
  for(int i = 1; i <= 7; ++i)
    days[i] += weeks;
  long long rem = mid % 7;
  for(int i = 1; i <= rem; ++i)
    days[i] += 1;
  
  if(days[2] + days[3] + days[6] <= a && days[1] + days[4] <= b && days[5] + days[7] <= c)
    return true;
  return false;
}

int main() {
  scanf("%lld %lld %lld", &a, &b, &c);

  long long best = 0;
  for(int i = 1; i <= 7; ++i) {
    long long l = 0, r = 1e15, mid, res = -1;
    while(l <= r) {
      mid = (l + r) >> 1;
      if(can(i, mid))
        l = mid + 1, res = mid;
      else
        r = mid - 1;
    }
    best = max(best, res);
  }

  printf("%lld\n", best);

  return 0;
}
