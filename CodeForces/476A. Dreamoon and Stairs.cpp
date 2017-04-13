#include <stdio.h>

using namespace std;

int main() {
  int n, m;
  scanf("%d%d", &n, &m);

  int twos = n / 2, ones = n - (twos * 2);
  
  while(twos >= 0 && ones >= 0 && (twos + ones) % m != 0) {
    twos--;
    ones += 2;
  }
  
  if(twos < 0 || ones < 0) puts("-1");
  else printf("%d\n", twos + ones);
  
  return 0;
}

