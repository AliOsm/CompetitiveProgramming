#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr;

int main() {
  int n;
  cin >> n;
  
  arr.resize(n);
  for(int i = 0; i < n; i++) cin >> arr[i];
  sort(arr.begin(), arr.end());
  
  long long minDist = 1e18;
  
  for(int i = 1; i < n; i++)
    minDist = min(minDist, 1LL * arr[i] - arr[i - 1]);
  
  long long res = 0;
  
  for(int i = 1; i < n; i++)
    if(arr[i] - arr[i - 1] == minDist)
      res++;
  
  cout << minDist << ' ' << res << endl;
  
  return 0;
}

