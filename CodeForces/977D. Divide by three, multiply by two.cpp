#include <bits/stdc++.h>

using namespace std;

int const N = 101;
long long const MAX = 3e18 + 500;
int n;
long long a[N], sol[N];
vector<long long> all;
map<long long, int> fr;

void rec(int idx, long long num) {
  sol[idx] = num;

  if(idx == n - 1) {
    for(int i = 0; i < n; ++i) {
      if(i != 0)
        cout << ' ';
      cout << sol[i];
    }
    cout << endl;
    exit(0);
  }

  if(num % 3 == 0 && fr.count(num / 3) && fr[num / 3] > 0) {
    --fr[num / 3];
    rec(idx + 1, num / 3);
    ++fr[num / 3];
  }

  if(num < MAX && fr.count(num * 2) && fr[num * 2] > 0) {
    --fr[num * 2];
    rec(idx + 1, num * 2);
    ++fr[num * 2];
  }
}

int main() {
  cin >> n;
  for(int i = 0; i < n; ++i) {
    cin >> a[i];
    ++fr[a[i]];
    all.push_back(a[i]);
  }

  sort(all.begin(), all.end());
  all.resize(unique(all.begin(), all.end()) - all.begin());

  for(int i = 0; i < all.size(); ++i) {
    --fr[all[i]];
    rec(0, all[i]);
    ++fr[all[i]];
  }

  return 0;
}
