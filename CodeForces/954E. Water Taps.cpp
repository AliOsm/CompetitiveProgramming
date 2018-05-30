#include <bits/stdc++.h>

using namespace std;

int const N = 2e5 + 1;
int n, T;
long long to1, to2;
pair<int, int> at[N];

int main() {
  scanf("%d %d", &n, &T);
  for(int i = 0; i < n; ++i) {
  	scanf("%d", &at[i].second);
  	to2 += at[i].second;
  }
  for(int i = 0; i < n; ++i) {
  	scanf("%d", &at[i].first);
  	to1 += 1ll * at[i].first * at[i].second;
  }

  sort(at, at + n);
  reverse(at, at + n);

  if(to1 < T * to2) {
  	T *= -1;
    for(int i = 0; i < n; ++i)
      at[i].first *= -1;
    reverse(at, at + n);
    to1 *= -1;
  }

  int i = 0;
  while(i < n && to1 > T * to2)
  	to1 -= 1ll * at[i].first * at[i].second, to2 -= at[i].second, ++i;
  --i;

  double l = 0, r = at[i].second, mid, res = 0;
  for(int j = 0; j < 100; ++j) {
  	mid = (l + r) / 2;
  	if(1ll * mid * at[i].first + to1 <= 1ll * T * (mid + to2))
  		res = l = mid;
  	else
  		r = mid;
  }

  printf("%.10lf\n", to2 + res);

  return 0;
}
