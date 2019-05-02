#include <bits/stdc++.h>

using namespace std;

int const N = 2e5 + 10;
int n, a[N];

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i)
    scanf("%d", a + i);
  
  int l = 0, r = n - 1, lst = -1;
  string res = "";

  while(l <= r) {
    if(a[l] <= a[r] && a[l] >= lst) {
      lst = a[l++];
      res += 'L';
    } else if(a[r] <= a[l] && a[r] >= lst) {
      lst = a[r--];
      res += 'R';
    } else if(a[l] >= lst) {
      lst = a[l++];
      res += 'L';
    } else if(a[r] >= lst) {
      lst = a[r--];
      res += 'R';
    } else
      break;
  }

  printf("%d\n", int(res.length()));
  puts(res.c_str());

  return 0;
}
