#include <bits/stdc++.h>

using namespace std;

int n, a[101];

bool can(int mid) {
  for(int i = 0; i < n; ++i)
    if(i / mid > a[i])
      return false;
  return true;
}

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i)
    scanf("%d", a + i);
  sort(a, a + n);
  
  for(int i = 1; i < 101; ++i)
    if(can(i)) {
      printf("%d\n", i);
      return 0;
    }
  
  return 0;
}
