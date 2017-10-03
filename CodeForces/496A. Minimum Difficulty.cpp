#include <bits/stdc++.h>

using namespace std;

int const N = 101;
int n, a[N];
vector<int> tmp;

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i)
    scanf("%d", a + i);
  
  int sol = 1e9;
  for(int i = 1, res; i < n - 1; ++i) {
    tmp.clear();
    res = 0;
    
    for(int j = 0; j < n; ++j)
      if(j != i)
        tmp.push_back(a[j]);
    
    for(int j = 1; j < (int)tmp.size(); ++j)
      res = max(res, tmp[j] - tmp[j - 1]);
    
    sol = min(sol, res);
  }
  printf("%d\n", sol);
  
  return 0;
}
