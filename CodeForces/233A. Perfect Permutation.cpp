#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  
  if(n & 1) {
    puts("-1");
    return 0;
  }
  
  for(int i = 0; i < n; i += 2)
    printf("%d %d ", i + 2, i + 1);
  puts("");
  
  return 0;
}

