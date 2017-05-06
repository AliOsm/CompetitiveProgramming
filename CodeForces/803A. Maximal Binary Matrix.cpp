#include <stdio.h>

using namespace std;

int const N = 101;
bool grid[N][N];

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  
  if(n * n < k) {
    puts("-1");
  } else if(n * n == k) {
    for(int i = 0; i < n; ++i) {
      for(int j = 0; j < n; ++j) {
        if(j) putchar(' ');
        putchar('1');
      }
      putchar('\n');
    }
  } else {
    int i = 0, j = 0, x = 0, y = 0, c = 0;
    while(k > 0) {
      if(i == x && j == y) {
        grid[i][j] = 1;
        --k;
      } else {
        grid[i][j] = 1;
        grid[x][y] = 1;
        k -= 2;
      }
      
      ++j;
      ++x;
      
      if(k < 0) {
        --j;
        --x;
        grid[i][j] = 0;
        grid[x][y] = 0;
        ++j;
        ++x;
        k += 2;
        c++;
        i = j = x = y = c;
      } else if(j == n && x == n) {
        c++;
        i = j = x = y = c;
      }
    }
    
    if(k < 0) {
      puts("-1");
      return 0;
    } else {
      for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
          if(j) putchar(' ');
          printf("%d", grid[i][j]);
        }
        putchar('\n');
      }
    }
  }

  return 0;
}
