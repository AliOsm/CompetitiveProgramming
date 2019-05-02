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

  while(l <= r && a[l] != a[r]) {
    if(a[l] < a[r] && a[l] > lst) {
      lst = a[l++];
      res += 'L';
    } else if(a[r] < a[l] && a[r] > lst) {
      lst = a[r--];
      res += 'R';
    } else if(a[l] > lst) {
      lst = a[l++];
      res += 'L';
    } else if(a[r] > lst) {
      lst = a[r--];
      res += 'R';
    } else
      break;
  }

  if(l == r && a[l] > lst)
    res += 'L', ++l;
  else if(l < r && a[l] == a[r] && a[l] > lst) {
    int lst1 = lst;
    string res1 = res;
    int lst2 = lst;
    string res2 = res;

    for(int i = l; i <= r; ++i)
      if(a[i] > lst1) {
        lst1 = a[i];
        res1 += 'L';
      } else
        break;
    
    for(int i = r; i >= l; --i) {
      if(a[i] > lst2) {
        lst2 = a[i];
        res2 += 'R';
      } else
        break;
    }
    
    if(res1.length() > res2.length())
      res = res1;
    else
      res = res2;
  }

  printf("%d\n", int(res.length()));
  puts(res.c_str());

  return 0;
}
