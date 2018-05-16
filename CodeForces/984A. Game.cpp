#include <bits/stdc++.h>

using namespace std;

int n, a[1001];
bool vis[1001];

int main() {
  cin >> n;
  for(int i = 0; i < n; ++i)
    cin >> a[i];

  sort(a, a + n);

  int cnt = n - 1;
  for(int i = 0, j = n - 1; i < j; ++i, --j) {
    a[j] = -1;
    --cnt;
    if(cnt == 0)
      break;
    a[i] = -1;
    --cnt;
    if(cnt == 0)
      break;
  }

  for(int i = 0; i < n; ++i)
    if(a[i] != -1) {
      cout << a[i] << endl;
      return 0;
    }

  return 0;
}
