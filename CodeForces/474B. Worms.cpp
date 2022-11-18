#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, x, k;
  cin >> n;
  
  vector<int> p(n), arr(n);

  for(int i = 0; i < n; i++)
    cin >> p[i];
  
  arr[0] = p[0];
  
  for(int i = 1; i < n; i++)
    arr[i] = arr[i - 1] + p[i];
  
  cin >> x;
  for(int i = 0; i < x; i++) {
    cin >> k;
    cout << (lower_bound(arr.begin(), arr.end(), k) - arr.begin()) + 1 << endl;
  }
  
  return 0;
}
