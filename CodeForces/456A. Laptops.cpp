#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;

int const N = 1e5 + 1;
int n;
pair<int, int> a[N];

bool cmp(pair<int, int> a, pair<int, int> b) {
  if(a.F != b.F)
    return a.F < b.F;
  if(a.S != b.S)
    return b.S > a.S;
  return true;
}

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i)
    scanf("%d %d", &a[i].F, &a[i].S);
  sort(a, a + n, cmp);
  
  for(int i = 0; i < n - 1; ++i) {
    if(a[i].F < a[i + 1].F && a[i].S > a[i + 1].S) {
      puts("Happy Alex");
      return 0;
    }
  }
  puts("Poor Alex");
  
  return 0;
}
