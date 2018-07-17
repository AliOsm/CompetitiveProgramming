#include <bits/stdc++.h>

using namespace std;

int n, m;
list<int> l;

int main() {
  int kase = 1;
  while(scanf("%d %d", &n, &m) && n != 0 && m != 0) {
    printf("Case %d:\n", kase++);

    l.clear();

    int need = min(n, 1000);
    for(int i = 1; i <= need; ++i)
      l.push_back(i);
    
    for(int i = 0; i < m; ++i) {
      char ch;
      scanf(" %c", &ch);

      if(ch == 'N') {
        printf("%d\n", l.front());
        l.push_back(l.front());
        l.pop_front();
      } else {
        int tmp;
        scanf("%d", &tmp);
        l.remove(tmp);
        l.push_front(tmp);
      }
    }
  }

  return 0;
}
