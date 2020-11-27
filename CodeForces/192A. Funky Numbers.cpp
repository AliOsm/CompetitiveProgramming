#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;
int n;
set<long long> st;

int main() {
  scanf("%d", &n);

  for(int i = 1; i < N; ++i)
    st.insert(1ll * i * (i + 1) / 2);
  
  for(set<long long>::iterator it = st.begin(); it != st.end(); ++it) {
    if(n - (*it) > 0 && st.count(n - (*it))) {
      puts("YES");
      return 0;
    }
  }

  puts("NO");

  return 0;
}
