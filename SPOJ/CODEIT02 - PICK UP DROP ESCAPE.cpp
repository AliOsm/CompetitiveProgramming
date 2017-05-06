#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> arr;

int trY(int index, int sum, int taken) {
  if(taken == m)
    return sum;
  
  if(index == n) {
    if(taken == m)
      return sum;
    
    return 0;
  }
  
  return max(trY(index + 1, sum, taken), trY(index + 1, sum ^ arr[index], taken + 1));
}

int main() {
  int t;
  scanf("%d", &t);
  
  while(t-- != 0) {
    scanf("%d%d", &n, &m);
    
    arr.clear();
    arr.resize(n);
    for(int i = 0; i < n; ++i)
      scanf("%d", &arr[i]);
    
    printf("%d\n", trY(0, 0, 0));
  }
  
  return 0;
}

