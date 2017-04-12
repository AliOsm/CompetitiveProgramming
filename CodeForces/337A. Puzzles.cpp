#include <stdio.h>
#include <algorithm>

using namespace std;

int arr[51];

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  
  for(int i = 0; i < m; i++)
    scanf("%d", &arr[i]);
  sort(arr, arr + m);
  
  int l = 0, r = n - 1, res = 1e4;
  while(r < m)
    res = min(res, arr[r++] - arr[l++]);
  
  printf("%d\n", res);
  
  return 0;
}

