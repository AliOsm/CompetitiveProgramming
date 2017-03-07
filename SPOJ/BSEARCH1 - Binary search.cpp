#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

vector<long long> arr;

int main() {
  int n, m;
  scanf("%d%d", &n, &m);

  arr.resize(n);
  for(int i = 0; i < n; i++) scanf("%lld", &arr[i]);

  long long a, i;
  while(m--) {
    scanf("%lld", &a);

    i = lower_bound(arr.begin(), arr.end(), a) - arr.begin();

    if(i == arr.size() || arr[i] != a) {
      puts("-1");
      continue;
    }

    printf("%lld\n", i);
  }

  return 0;
}

