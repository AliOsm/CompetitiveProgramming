#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int const N = 2 * 1e5 + 1;
int a[N];
vector<int> zeros;

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) {
    scanf("%d", a + i);
    if(a[i] == 0)
      zeros.push_back(i);
  }
  
  int index;
  for(int i = 0; i < n; ++i) {
    index = lower_bound(zeros.begin(), zeros.end(), i) - zeros.begin();
    if(index == zeros.size())
      --index;
    
    if(i) putchar(' ');
    if(index > 0)
      printf("%d", min(int(abs(i - zeros[index])), int(abs(i - zeros[index - 1]))));
    else
      printf("%d", abs(i - zeros[index]));
  }
  putchar('\n');

  return 0;
}
