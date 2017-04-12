#include <stdio.h>
#include <bitset>

using namespace std;

bitset<101> bs;

int main() {
  int n;
  scanf("%d", &n);
  
  int p, tmp;
  
  scanf("%d", &p);
  while(p--) {
    scanf("%d", &tmp);
    bs[tmp] = 1;
  }
  
  scanf("%d", &p);
  while(p--) {
    scanf("%d", &tmp);
    bs[tmp] = 1;
  }
  
  for(int i = 1; i <= n; i++)
    if(!bs[i]) {
      puts("Oh, my keyboard!");
      return 0;
    }
  
  puts("I become the guy.");
  
  return 0;
}

