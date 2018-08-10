/*
  Idea:
    - By brute forcing the tests you can see that if:
      . n or m equal to 1 the answer will be ceil(max(n, m) / 2)
      . n or m divisible by 3 the answer will be 2
      . otherwise the answer is 1
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  scanf("%d %d", &n, &m);

  if(min(n, m) == 1)
    printf("%d\n", (n + m) / 2);
  else if(n % 3 == 0 || m % 3 == 0)
    puts("2");
  else
    puts("1");

  return 0;
}
