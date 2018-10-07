#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int const N = 1e5 + 1;

int main() {
  int a, b;
  cin >> a >> b;
  int ans = a * b;
  cout << ans << endl;

  vector<int> vi;
  for(int i = 1; i <= ans; ++i)
    vi.push_back(i);

  for(int i = ans - a; i >= 0; i -= a)
    for(int j = i; j < i + a; ++j)
      cout << vi[j] << " ";

  return 0;
}
