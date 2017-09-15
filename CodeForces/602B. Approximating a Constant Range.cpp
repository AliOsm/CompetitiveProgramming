#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;
int n, a[N], fr[N];
queue<int> q;
set<int> st;

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i)
    scanf("%d", a + i);
  
  int r = 0, res = 0, mn = 1e9, mx = -1e9;
  while(r < n) {
    ++fr[a[r]];
    q.push(a[r]);
    st.insert(a[r]);

    mn = min(mn, a[r]);
    mx = max(mx, a[r]);
    
    while(!q.empty() && fr[mx] && fr[mn] && mx - mn > 1) {
      int tmp = q.front();
      q.pop();
      --fr[tmp];
    }
    
    if(fr[mn] == 0) {
      st.erase(st.begin());
      if(!st.empty());
        mn = *st.begin();
    }
    
    if(fr[mx] == 0) {
      st.erase(--st.end());
      if(!st.empty())
        mx = *(--st.end());
    }
    
    res = max(res, (int)q.size());
    ++r;
  }
  
  cout << res << endl;
  
  return 0;
}
