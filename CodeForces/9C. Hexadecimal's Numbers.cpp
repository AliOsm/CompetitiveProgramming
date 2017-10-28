#include <bits/stdc++.h>

using namespace std;

vector<long long> all;
void rec(long long sum, int idx) {
  if(idx == 10) {
    all.push_back(sum);
    return;
  }
  
  rec(sum, idx + 1);
  rec(sum * 10, idx + 1);
  rec(sum * 10 + 1, idx + 1);
}

int main() {
  rec(1, 0);
  sort(all.begin(), all.end());
  all.resize(unique(all.begin(), all.end()) - all.begin());
  
  int n, res = 0;
  scanf("%d", &n);
  for(int i = 0; i < (int)all.size(); ++i) {
    if(all[i] > n)
      break;
    ++res;
  }
  printf("%d\n", res);
  
  return 0;
}
