#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k, l, r, mid, res;
vector<int> arr;

bool can(int mid) {
  int tmpK = k;
  
  for(int i = n - 1; i >= 0; i--) {
    tmpK -= (arr[i]/mid);
    if(tmpK <= 0) return true;
  }
  
  return false;
}

int main() {
  int t;
  cin >> t;
  
  while(t--) {
    cin >> n >> k;
    arr.clear();
    arr.resize(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());
    
    l = 1; r = arr.back() + 1; res = 0;
    while(l <= r) {
      mid = (l + r) / 2;
      
      if(can(mid)) {
        res = mid;
        l = mid + 1;
      } else
        r = mid - 1;
    }
    
    cout << res << endl;
  }
  
  return 0;
}

