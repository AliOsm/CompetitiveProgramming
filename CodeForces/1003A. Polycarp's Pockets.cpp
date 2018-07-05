#include <bits/stdc++.h>

using namespace std;

int n, a[101];
set<int> st;

int main() {
  int cnt = 0;
  cin >> n;
  for(int i = 0; i < n; ++i)
    cin >> a[i];

  int res = 0;
  while(cnt != n) {
    st.clear();
    for(int i = 0; i < n; ++i)
      if(a[i] != -1 && st.count(a[i]) == 0)
        st.insert(a[i]), a[i] = -1, ++cnt;
    ++res;
  }

  cout << res << endl;

  return 0;
}
