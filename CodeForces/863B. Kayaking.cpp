#include <bits/stdc++.h>

using namespace std;

int const N = 101;
int n, a[N];
vector<int> all;

int main() {
  scanf("%d", &n);
  n *= 2;
  for(int i = 0; i < n; ++i)
    scanf("%d", a + i);
  sort(a, a + n);
  
  int sol = 1e9;
  for(int i = 0; i < n; ++i)
    for(int j = i + 1; j < n; ++j) {
      all.clear();
      for(int k = 0; k < n; ++k)
        if(k != i && k != j)
          all.push_back(a[k]);
      
      int res = 0;
      for(int k = 0; k < (int)all.size(); k += 2)
        res += (all[k + 1] - all[k]);
      
      sol = min(sol, res);
    }
  
  printf("%d\n", sol);
  
  return 0;
}
