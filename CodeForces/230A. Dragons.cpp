#include <stdio.h>
#include <utility>
#include <algorithm>

using namespace std;

pair<int, int> dragons[1001];

int main() {
  int s, n;
  scanf("%d%d", &s, &n);
  
  for(int i = 0; i < n; i++)
    scanf("%d%d", &dragons[i].first, &dragons[i].second);
  sort(dragons, dragons + n);
  
  for(int i = 0; i < n; i++) {
    if(s > dragons[i].first) s += dragons[i].second;
    else {
      puts("NO");
      return 0;
    }
  }
  
  puts("YES");
  
  return 0;
}

