#include <bits/stdc++.h>

using namespace std;

int n;
set<int> st;

int main() {
  scanf("%d", &n);

  int res = 0;
  while(st.count(n) != 1) {
    st.insert(n);
    n += 1;
    while(n % 10 == 0)
      n /= 10;
  }

  printf("%d\n", int(st.size()));

  return 0;
}
