#include <stdio.h>

using namespace std;

int arr[101];

int main() {
  int n, d;
  scanf("%d%d", &n, &d);
  
  for(int i = 0; i < n; i++)
    scanf("%d", arr + i);
  
  int res = 0;
  for(int i = 0; i < n; i++) {
    d -= arr[i];
    d -= 10;
    
    if(d < 0 && i != n - 1) {
      puts("-1");
      return 0;
    }
    
    if(d < 0 && i == n - 1) {
      d += 10;
      if(d >= 5)
        res += d / 5;
      printf("%d\n", d < 0 ? -1 : res);
      return 0;
    }
    
    res += 2;
  }
  
  if(d >= 5)
    res += d / 5;
  printf("%d\n", res);
  
  return 0;
}

