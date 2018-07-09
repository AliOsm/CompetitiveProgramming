#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 10;
int n, nxt[N], prv[N];
long long a[N];
stack<int> st;

int main() {
  while(scanf("%d", &n) && n != 0) {
    for(int i = 0; i < n; ++i)
      scanf("%lld", a + i);

    for(int i = 0; i < n; ++i) {
      while(!st.empty() && a[i] < a[st.top()]) {
        nxt[st.top()] = i;
        st.pop();
      }

      st.push(i);
    }

    while(!st.empty()) {
      nxt[st.top()] = n;
      st.pop();
    }

    for(int i = n - 1; i >= 0; --i) {
      while(!st.empty() && a[i] < a[st.top()]) {
        prv[st.top()] = i;
        st.pop();
      }

      st.push(i);
    }

    while(!st.empty()) {
      prv[st.top()] = -1;
      st.pop();
    }

    long long res = 0;
    for(int i = 0; i < n; ++i)
      res = max(res, (nxt[i] - prv[i] - 1) * a[i]);
    printf("%lld\n", res);
  }

  return 0;
}
