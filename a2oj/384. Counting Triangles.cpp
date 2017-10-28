#include <bits/stdc++.h>

using namespace std;

int t, n, res;
pair<int, int> a[101];

long double slope(pair<int, int> src, pair<int, int> dist) {
   return atan(1.0 * (dist.second - src.second) / (dist.first - src.first)) * 180.0 / M_PI;
}

long double angle(pair<int, int> src, pair<int, int> dist1, pair<int, int> dist2) {
  long double m1 = slope(src, dist1);
  long double m2 = slope(src, dist2);
  return atan(abs((m2 - m1) / ((m1 * m2) + 1.0))) * 180.0 / M_PI;
}

int main() {
  scanf("%d", &t);
  for(int kase = 1; t-- != 0; ++kase) {
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
      scanf("%d %d", &a[i].first, &a[i].second);
    
    res = 0;
    for(int i = 0; i < n; ++i)
      for(int j = i + 1; j < n; ++j)
        for(int k = j + 1; k < n; ++k) {
          long double ijk, jik, kij;
          ijk = angle(a[i], a[j], a[k]);
          jik = angle(a[j], a[i], a[k]);
          kij = angle(a[k], a[i], a[j]);
          if(ijk < 180.0 && jik < 180.0 && kij < 180.0 && ijk != 0 && jik != 0 && kij != 0)
            ++res;
        }
    printf("Test case #%d: %d triangle(s) can be formed.\n\n", kase, res);
  }
  
  return 0;
}

