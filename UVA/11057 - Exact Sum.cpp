#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> arr;

int main() {
  int n, m, tmp, u, v, x, y;

  while(cin >> n) {
    arr.clear();
    arr.resize(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    cin >> m;
    tmp = m;

    sort(arr.begin(), arr.end());

    for(int i = 0; i <= m; i++, m--) {
      u = lower_bound(arr.begin(), arr.end(), i) - arr.begin();
      v = lower_bound(arr.begin(), arr.end(), m) - arr.begin();

      if((u != v || (u == v && arr[u] == arr[v+1])) && u != arr.size() && v != arr.size() && (arr[u] + arr[v]) == tmp) {
        x = arr[u];
        y = arr[v];
      }
    }

    cout << "Peter should buy books whose prices are " << x << " and " << y << "." << endl << endl;
  }

  return 0;
}
