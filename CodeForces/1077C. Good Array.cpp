#include <bits/stdc++.h>

using namespace std;

int const N = 2e5 + 1;
int n, a[N];
long long t;
vector<int> all;
multiset<long long> st;

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i)
    scanf("%d", a + i), t += a[i], st.insert(a[i]);

  for(int i = 0; i < n; ++i) {
    t -= a[i];
    multiset<long long>::iterator it;
    it = st.find(a[i]);
    st.erase(it);

    if(t % 2 == 0 && st.count(t / 2) != 0)
      all.push_back(i + 1);

    t += a[i];
    st.insert(a[i]);
  }

  printf("%d\n", int(all.size()));
  for(int i = 0; i < all.size(); ++i)
    printf("%d ", all[i]);
  puts("");

  return 0;
}
