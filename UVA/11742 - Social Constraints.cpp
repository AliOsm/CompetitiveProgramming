#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

struct constraint {
  int a, b, c;
  constraint(int a, int b, int c): a(a), b(b), c(c) {}
};

vector<int> indx;
vector<constraint> cons;

bool check(int a, int b, int c) {
  int indxa, indxb;
  for(int i = 0; i < (int)indx.size(); ++i)
    if(indx[i] == a)
      indxa = i;
    else if(indx[i] == b)
      indxb = i;
  
  if(c > 0)
    return abs(indxa - indxb) <= abs(c);
  
  return abs(indxa - indxb) >= abs(c);
}

int main() {
  int n, m;
  
  int a, b, c, res;
  bool ok;
  while(scanf("%d%d", &n, &m) && (n != 0 || m != 0)) {
    res = 0;
    
    indx.clear();
    for(int i = 0; i < n; ++i)
      indx.push_back(i);
    
    cons.clear();
    for(int i = 0; i < m; ++i) {
      scanf("%d%d%d", &a, &b, &c);
      cons.push_back(constraint(a, b, c));
    }
    
    do {
      ok = true;
      for(int i = 0; i < m; ++i) {
        ok = check(cons[i].a, cons[i].b, cons[i].c);
        
        if(!ok)
          break;
      }
      
      if(ok)
        ++res;
    } while(next_permutation(indx.begin(), indx.end()));
    
    printf("%d\n", res);
  }
  
  return 0;
}

