#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  
  if(min(n, m) % 2 == 0) puts("Malvika");
  else puts("Akshat");
  
  return 0;
}

