#include <stdio.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  
  int by, bm, ay, am, ny, nm;
  while(t--) {
    scanf("%d%d%d%d", &by, &bm, &ay, &am);
    
    ny = by + ay;
    nm = bm + am;
    if(nm > 12) {
      ny++;
      nm -= 12;
    }
    
    printf("%d %d\n", ny, nm);
  }
  
  return 0;
}

