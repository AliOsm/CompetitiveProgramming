#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

long long n, m;
vector<long long> arr;

bool can(long long mid) {
  long long tmp = m - 1, cur = 0;
  
  while(tmp) {
    cur = lower_bound(arr.begin(), arr.end(), arr[cur] + mid) - arr.begin();
    
    if(cur == arr.size())
      return false;
    
    tmp--;
  }
  
  return true;
}

int main() {
  long long t;
  scanf("%lld", &t);
  
  long long l, r, mid, res;
  while(t--) {
    scanf("%lld%lld", &n, &m);
    
    arr.clear();
    arr.resize(n);
    
    for(int i = 0; i < n; i++)
      scanf("%lld", &arr[i]);
    
    sort(arr.begin(), arr.end());
    
    l = 1; r = 1e12; res = 0;
    while(l <= r) {
      mid = (l + r) / 2;
      
      if(can(mid)) {
        res = mid;
        l = mid + 1;
      } else
        r = mid - 1;
    }
    
    printf("%lld\n", res);
  }

  return 0;
}

