#include <stdio.h>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;

vector<vector<int> > pre;
int votes[101];

int main() {
  int t;
  scanf("%d", &t);
  
  int c, v;
  while(t--) {
    memset(votes, 0, sizeof votes);
    
    scanf("%d %d", &c, &v);
    
    pre.clear();
    pre.resize(v);
    for(int i = 0; i < v; i++) {
      pre[i].resize(c);
      for(int j = 0; j < c; j++) {
        scanf("%d", &pre[i][j]);
        if(!j) votes[pre[i][j]]++;
      }
    }
    
    int mx = 0, indx;
    for(int i = 1; i <= c; i++)
      if(votes[i] > mx) {
        mx = votes[i];
        indx = i;
      }
    
    if(mx >= v / 2 + 1) printf("%d 1\n", indx);
    else {
      int f = indx, s, tmp = 0;
      for(int i = 1; i <= c; i++)
        if(i != f && votes[i] > tmp && votes[i] <= mx) {
          s = i;
          tmp = votes[i];
        }
      
      int fv = 0, sv = 0;
      for(int i = 0; i < v; i++)
        for(int j = 0; j < c; j++) {
          if(pre[i][j] == f) {
            fv++;
            break;
          }
          
          if(pre[i][j] == s) {
            sv++;
            break;
          }
        }
      
      if(fv > sv) printf("%d 2\n", f);
      else printf("%d 2\n", s);
    }
  }
  
  return 0;
}

