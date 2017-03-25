#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr;

int main() {
  int n, m;
  scanf("%d", &n);
  arr.resize(n);
  for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
  scanf("%d", &m);
  
  int a, b, tmp;
  while(m--) {
    scanf("%d", &tmp);
    a = lower_bound(arr.begin(), arr.end(), tmp) - arr.begin();
    b = upper_bound(arr.begin(), arr.end(), tmp) - arr.begin();
    
    if(a > 0) printf("%d", arr[a-1]);
    else putchar('X');
    putchar(' ');
    if(b == arr.size()) puts("X");
    else printf("%d\n", arr[b]);
  }
  
  return 0;
}

