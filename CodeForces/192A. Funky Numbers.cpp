#include <bits/stdc++.h>

using namespace std;

int n;
set<long long> st;

int main() {
  scanf("%d", &n);

  for(int i = 1; i*(i+1)/2 < n; ++i)
    st.insert(i * (i + 1) / 2);
  
  for(auto it = st.begin(); it != st.end(); ++it) {
    if(st.count(n - (*it))) {
      puts("YES");
      return 0;
    }
  }

  puts("NO");

  return 0;
}
