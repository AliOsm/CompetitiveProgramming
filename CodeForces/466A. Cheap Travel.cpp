#include <stdio.h>

using namespace std;

int main() {
  int n, m, a, b, res = 1e9;
  scanf("%d%d%d%d", &n, &m, &a, &b);
  
  for(int i = 0; i <= 1000; i++)
    if(i * m + j >= n)
      res = min(res, i * b + max(0, n - i * m) * a);
  
  printf("%d\n", res);
  
  return 0;
}

