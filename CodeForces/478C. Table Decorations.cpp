#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int arr[3];

int main() {
  scanf("%d%d%d", &arr[0], &arr[1], &arr[2]);
  sort(arr, arr + 3);
  
  if((1LL * arr[0] + arr[1] + arr[2]) / 3 > (1LL * arr[0] + arr[1]))
    printf("%lld\n", 1LL * arr[0] + arr[1]);
  else
    printf("%lld\n", (1LL * arr[0] + arr[1] + arr[2]) / 3);
  
  return 0;
}

