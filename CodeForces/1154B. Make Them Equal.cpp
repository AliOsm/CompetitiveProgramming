#include <bits/stdc++.h>

using namespace std;

int const N = 1e2 + 10;
int n, a[N];
set<int> nums, diffs;

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i)
    scanf("%d", a + i), nums.insert(a[i]);
  sort(a, a + n);
  for(int i = 1; i < n; ++i) {
    if(a[i] - a[i-1] == 0)
      continue;
    diffs.insert(a[i] - a[i-1]);
  }
  
  if(nums.size() == 1) {
    puts("0");
  } else if(nums.size() == 2) {
    if((*diffs.begin()) % 2 == 0)
      printf("%d\n", (*diffs.begin()) / 2);
    else
      printf("%d\n", (*diffs.begin()));
  } else if(nums.size() == 3 && diffs.size() == 1) {
    printf("%d\n", (*diffs.begin()));
  } else {
    puts("-1");
  }

  return 0;
}
