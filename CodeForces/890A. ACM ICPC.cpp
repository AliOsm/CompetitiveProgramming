#include <bits/stdc++.h>

using namespace std;

int const N = 7;
int n, m, q, p, x, y, a[N];

int main() {
  for(int i = 0; i < 6; ++i)
    scanf("%d", &a[i]);
  
  vector<int> idx;
  for(int i = 0; i < 6; ++i)
    idx.push_back(i);
  
  do {
    if(a[idx[0]] + a[idx[1]] + a[idx[2]] == a[idx[3]] + a[idx[4]] + a[idx[5]]) {
      puts("YES");
      return 0;
    }
  } while(next_permutation(idx.begin(), idx.end()));
  
  puts("NO");
  
  return 0;
}

