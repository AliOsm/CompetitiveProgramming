#include <bits/stdc++.h>

using namespace std;

int const N = 2e5 + 1;
int n, a[N], b[N];
multiset<int> st;

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i)
    scanf("%d", a + i);
  for(int i = 0; i < n; ++i)
    scanf("%d", b + i), st.insert(b[i]);
  
  for(int i = 0, need; i < n; ++i) {
    need = n - a[i];
    multiset<int>::iterator it = st.lower_bound(need);
    if(it == st.end())
      it = st.begin();
    
    printf("%s%d", i == 0 ? "" : " ", (a[i] + (*it)) % n);

    st.erase(it);
  }

  puts("");

  return 0;
}
