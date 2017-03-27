#include <stdio.h>
#include <vector>
#include <cmath>

using namespace std;

vector<int> d;

int main() {
  int t;
  scanf("%d", &t);
  
  int n, sqrtn, res;
  while(t--) {
    res = 0;
    d.clear();
    
    scanf("%d", &n);
    sqrtn = sqrt(n);
    
    for(int i = 1; i <= sqrtn; i++)
      if(n % i == 0) {
        d.push_back(i);
        if(i * i != n)
          d.push_back(n / i);
      }
    
    for(int i = 0; i < d.size(); i++) 
      if(d[i] != n)
        res += d[i];
    
    printf("%d\n", res);
  }
  
  return 0;
}

