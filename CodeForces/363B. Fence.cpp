#include <iostream>
#include <vector>

using namespace std;

int const N = 1.5e5 + 1;
int cum[N];
vector<int> arr;

int main() {
  int n, k;
  cin >> n >> k;

  arr.resize(n);
  for(int i = 0; i < n; i++) cin >> arr[i];

  cum[0] = 0;

  for(int i = 1; i < k; i++)
    cum[i] = cum[i-1] + arr[i-1];

  for(int i = k; i <= n; i++)
    cum[i] = cum[i-1] + arr[i-1] - arr[i-k-1];

  int mnv = 1e9, mni = 0;
  for(int i = k; i <= n; i++) {
    if(cum[i] < mnv) {
      mnv = cum[i];
      mni = i;
    }
  }

  if(mni == 0) cout << 1 << endl;
  else if(mni < k) cout << mni << endl;
  else  cout << mni - k + 1 << endl;
}
