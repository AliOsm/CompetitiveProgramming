#include <stdio.h>
#include <vector>

using namespace std;

vector<int> arr;

int main() {
  int t;
  scanf("%d", &t);
  
  int n, msf, meh, start, end, startTmp;
  for(int c = 1; t--; c++) {
    scanf("%d", &n);
    arr.clear();
    arr.resize(n);
    for(int i = 0; i < n-1; i++) scanf("%d", &arr[i]);
    
    msf = meh = start = end = startTmp = 0;
    for(int i = 0; i < n-1; i++) {
      meh += arr[i];
      
      if(meh < 0) {
        meh = 0;
        startTmp = i + 1;
      }
      
      if(msf < meh || (msf == meh && end - start < i - startTmp)) {
        msf = meh;
        start = startTmp;
        end = i;
      }
    }
    
    if(msf)
      printf("The nicest part of route %d is between stops %d and %d\n", c, start + 1, end + 2);
    else
      printf("Route %d has no nice parts\n", c);
  }
  
  return 0;
}

