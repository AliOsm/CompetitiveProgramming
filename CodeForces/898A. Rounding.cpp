#include <bits/stdc++.h>

using namespace std;

int n, m, tmp;

int main() {
  scanf("%d", &n);
  tmp = n;
  m = n;

  while(n % 10 != 0)
	  ++n;

  while(m % 10 != 0)
	  --m;

  if(n - tmp < tmp - m)
	  printf("%d\n", n);
  else
	  printf("%d\n", m);

  return 0;
}

