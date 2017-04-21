#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> sol;

int main() {
  int n, s;
  scanf("%d%d", &n, &s);

  int k, p;
  for(int i = 1; n--; i++) {
    scanf("%d", &k);

    while(k--) {
      scanf("%d", &p);
      if(p < s)
        sol.push_back(i);
    }
  }

  sol.resize(unique(sol.begin(), sol.end()) - sol.begin());

  printf("%d\n", sol.size());
  for(int i = 0; i < sol.size(); i++) {
    if(i) putchar(' ');
    printf("%d", sol[i]);
  }
  putchar('\n');

  return 0;
}

