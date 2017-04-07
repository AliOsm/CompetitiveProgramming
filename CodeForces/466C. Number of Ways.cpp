#include <stdio.h>

using namespace std;

int const N = 5 * 1e5 + 1;
int arr[N];

int main() {
  int n;
  scanf("%d", &n);
  
  long long t = 0;
  for(int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
    t += arr[i];
  }
  
  if(t % 3 != 0)
    puts("0");
  else {
    t /= 3;
    
    long long tmp = 0, res = 0, cnt = 0;
    
    for(int i = 0; i < n - 1; i++) {
      tmp += arr[i];
      if(tmp == t * 2)
        res += cnt;
      if(tmp == t)
        cnt++;
    }
  
    printf("%lld\n", res);
  }
  
  return 0;
}

