#include <stdio.h>
#include <vector>

using namespace std;

vector<int> pro, math, pe;

int main() {
  int n;
  scanf("%d", &n);
  
  int tmp;
  for(int i = 1; i <= n; i++) {
    scanf("%d", &tmp);
    if(tmp == 1) pro.push_back(i);
    else if(tmp == 2) math.push_back(i);
    else pe.push_back(i);
  }
  
  int mn = min(pro.size(), min(math.size(), pe.size()));
  
  printf("%d\n", mn);
  for(int i = 0; i < mn; i++)
    printf("%d %d %d\n", pro[i], math[i], pe[i]);
  
  return 0;
}

