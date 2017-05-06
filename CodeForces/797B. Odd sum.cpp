#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  
  int tmp, mnOdd = 1e5, mxOdd = -1e5;
  long long res = 0;
  for(int i = 0; i < n; ++i) {
    scanf("%d", &tmp);
    
    if(tmp > 0) res += tmp;
    
    if(tmp < 0 && abs(tmp) % 2 == 1 && mxOdd < tmp)
      mxOdd = tmp;
    
    if(tmp > 0 && abs(tmp) % 2 == 1 && mnOdd > tmp)
      mnOdd = tmp;
  }
  
  if(res % 2 == 0)
    res -= min(mnOdd, -mxOdd);
  
  printf("%lld\n", res);
  
  return 0;
}

