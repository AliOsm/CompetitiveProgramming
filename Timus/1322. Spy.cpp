#include <bits/stdc++.h>

using namespace std;

int k, len;
char ori[1000001], sor[1000001], sol[1000001];
vector<int> idx_ori[100], idx_sor[100];

int main() {
  scanf("%d%s", &k, ori);
  len = strlen(ori);
  for(int i = 0; i < len; ++i)
    sor[i] = ori[i];
  sort(sor, sor + len);
  for(int i = 0; i < len; ++i) {
    if(islower(ori[i]))
      idx_ori[ori[i] - 'a'].push_back(i);
    else
      idx_ori[ori[i] - 'A' + 26].push_back(i);
    
    if(islower(sor[i]))
      idx_sor[sor[i] - 'a'].push_back(i);
    else
      idx_sor[sor[i] - 'A' + 26].push_back(i);
  }
  
  sol[0] = sor[k - 1];
  sol[len - 1] = ori[k - 1];
  sol[len] = '\0';
  for(int i = 1, cur = k - 1; i < len; ++i) {
    char ch = sor[cur];
    int before;
    if(islower(ch))
      before = lower_bound(idx_sor[ch - 'a'].begin(), idx_sor[ch - 'a'].end(), cur) - idx_sor[ch - 'a'].begin();
    else
      before = lower_bound(idx_sor[ch - 'A' + 26].begin(), idx_sor[ch - 'A' + 26].end(), cur) - idx_sor[ch - 'A' + 26].begin();
    
    int tmp;
    if(islower(ch))
      tmp = idx_ori[ch - 'a'][before];
    else
      tmp = idx_ori[ch - 'A' + 26][before];
    
    sol[i] = sor[tmp];
    cur = tmp;
  }
  
  printf("%s\n", sol);
  
  return 0;
}
