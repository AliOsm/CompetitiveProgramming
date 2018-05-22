/*
  Idea:
    - Sort the array and try to put the elements in either even or edd indexes
      and print the minimum answer.
*/

#include <bits/stdc++.h>

using namespace std;

int a[101];

int main() {
  int n;
  cin >> n;
  for(int i = 0; i < n / 2; ++i)
    cin >> a[i];
  sort(a, a + n / 2);

  int r1 = 0, r2 = 0;
  for(int i = 0, cnt = 1; i < n / 2; ++i, cnt += 2)
    if(a[i] != cnt)
      r1 += abs(cnt - a[i]);
  for(int i = 0, cnt = 2; i < n / 2; ++i, cnt += 2)
    if(a[i] != cnt)
      r2 += abs(cnt - a[i]);

  cout << min(r1, r2) << endl;

  return 0;
}
