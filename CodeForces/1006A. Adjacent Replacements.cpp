/*
  Idea:
    - If the number is odd print it as is, otherwise print it -1.
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 1001;
int n, a[N];

int main() {
  cin >> n;
  for(int i = 0; i < n; ++i)
    cin >> a[i];
  
  for(int i = 0; i < n; ++i)
    printf("%s%d", i == 0 ? "" : " ", a[i] - (a[i] % 2 == 0));
  puts("");
  
  return 0;
}
