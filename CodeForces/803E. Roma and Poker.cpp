#include <stdio.h>
#include <memory.h>
#include <math.h>
#include <cstdlib>

using namespace std;

int const N = 1001;
int n, k;
bool dp[N][2 * N];
char s[N];

bool calc(int index, int win) {
  if(index == n) {
    if(abs(win) == k) {
      puts(s);
      exit(0);
    } else
      return false;
  }
  
  if(abs(win) == k)
    return false;
  
  if(dp[index][win + 1000]) return false;
  dp[index][win + 1000] = 1;
  
  if(s[index] == 'D')
    return calc(index + 1, win);
  
  if(s[index] == 'L')
    return calc(index + 1, win - 1);
  
  if(s[index] == 'W')
    return calc(index + 1, win + 1);
  
  s[index] = 'D';
  calc(index + 1, win);
  
  s[index] = 'L';
  calc(index + 1, win - 1);
  
  s[index] = 'W';
  calc(index + 1, win + 1);
  
  s[index] = '?';
  
  return false;
}

int main() {
  scanf("%d%d%s", &n, &k, s);
  
  calc(0, 0);
  puts("NO");
  
  return 0;
}

