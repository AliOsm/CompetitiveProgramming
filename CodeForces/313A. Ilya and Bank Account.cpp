#include <stdio.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  
  if(n >= 0) {
    printf("%d\n", n);
    return 0;
  }
  
  int n1, n2;
  
  n1 = n / 10;
  n2 = (n1 / 10) * 10 + n % 10;
  
  printf("%d\n", max(n1, n2));
  
  return 0;
}

