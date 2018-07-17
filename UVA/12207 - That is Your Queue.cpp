/*
  Idea:
    - Using STL List we can track the queue.
    - For each `N` operation we print the front of the list.
    - For each `E x` operation we erase the element from the list and
      push it to the front.
    - The important observation is that we don't need all `n` to solve the queries,
      at most we need the first 1000 elements and in operation of type `E x` appears
      with `x` greater than 1000 then we can bring the element to the front of the list.
*/

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
