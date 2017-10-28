#include <bits/stdc++.h>

using namespace std;

int n, a[int(1e5 + 1)];
set<int> st, all;

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) {
    scanf("%d", a + i);
    all.insert(a[i]);
  }
  
  if(n == 1) {
    puts("-1");
    return 0;
  }
  
  sort(a, a + n);
  
  if(n == 2) {
    if(a[0] == a[1])
      printf("1\n%d\n", a[0]);
    else if((a[1] - a[0] - 1) & 1)
      printf("3\n%d %d %d\n", a[0] - (a[1] - a[0]), (a[0] + a[1]) / 2, a[1] + (a[1] - a[0]));
    else
      printf("2\n%d %d\n", a[0] - (a[1] - a[0]), a[1] + (a[1] - a[0]));
    return 0;
  }
  
  for(int i = 1; i < n; ++i)
    st.insert(a[i] - a[i - 1]);
  
  if(st.size() == 1) {
    if(all.size() == 1)
      printf("1\n%d\n", a[0]);
    else
      printf("2\n%d %d\n", a[0] - *st.begin(), a[n - 1] + *st.begin());
  } else if(st.size() == 2) {
    int mn = *st.begin();
    int mx = *(++st.begin());
    
    if(mn + mn == mx) {
      int tmp = 0, idx;
      for(int i = 1; i < n; ++i)
        if(a[i] - a[i - 1] == mx)
          ++tmp, idx = i;
      if(tmp == 1)
        printf("1\n%d\n", (a[idx] + a[idx - 1]) / 2);
      else
        puts("0");
    } else {
      puts("0");
    }
  } else {
    puts("0");
  }
  
  return 0;
}
