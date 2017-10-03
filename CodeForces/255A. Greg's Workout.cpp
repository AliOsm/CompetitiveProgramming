#include <bits/stdc++.h>

using namespace std;

int const N = 25;
int n, a[N];

int main() {
  int r1 = 0, r2 = 0, r3 = 0;
  scanf("%d", &n);
  for(int i = 0, tmp; i < n; ++i)
    scanf("%d", a + i);
  
  for(int i = 0; i < n; i += 3)
    r1 += a[i], r2 += a[i + 1], r3 += a[i + 2];
  
  int mx = max(r1, max(r2, r3));
  if(mx == r1)
    puts("chest");
  else if(mx == r2)
    puts("biceps");
  else if(mx == r3)
    puts("back");
  
  return 0;
}
