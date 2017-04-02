#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;

int main() {
  int n, m;
  cin >> n >> m;
  
  arr.resize(n);
  for(int i = 0; i < n; i++) cin >> arr[i];
  
  int l = 0, r = 0, res = 0, cum = 0;
  while(r < n) {
    cum += arr[r];
    
    while(cum > m) {
      cum -= arr[l];
      l++;
    }
    
    res = max(res, cum);
    r++;
  }
  
  cout << res << endl;
  
  return 0;
}

