#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int const N = 1e5 + 1;
long long scum[N], uscum[N];
vector<int> arr;

int main() {
  int n;
  cin >> n;

  arr.resize(n);
  for(int i = 0; i < n; i++) cin >> arr[i];

  uscum[0] = 0;
  for(int i = 1; i <= n; i++)
    uscum[i] = uscum[i-1] + arr[i-1];

  sort(arr.begin(), arr.end());

  scum[0] = 0;
  for(int i = 1; i <= n; i++)
    scum[i] = scum[i-1] + arr[i-1];

  int q;
  cin >> q;

  int t, a, b;
  while(q--) {
    cin >> t >> a >> b;

    if(t == 1)
      cout << uscum[b] - uscum[a-1] << endl;
    else
      cout << scum[b] - scum[a-1] << endl;
  }
}
