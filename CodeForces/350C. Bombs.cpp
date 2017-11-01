#include <bits/stdc++.h>

using namespace std;

struct point {
  int first, second, d;
  bool operator<(const point &p) const {
    return d < p.d;
  }
};

int const N = 1e5 + 1;
int n, whr, res;
point a[N];

int where(int &x, int &y) {
  if(x > 0 && y > 0)
    return 1;
  if(x < 0 && y > 0)
    return 2;
  if(x < 0 && y < 0)
    return 3;
  if(x > 0 && y < 0)
    return 4;
  if(x == 0)
    return 5;
  if(y == 0)
    return 6;
}

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) {
    scanf("%d %d", &a[i].first, &a[i].second);
    whr = where(a[i].first, a[i].second);
    a[i].d = abs(a[i].first) + abs(a[i].second);
    
    if(whr >= 1 && whr <= 4)
      res += 6;
    else
      res += 4;
  }
  
  sort(a, a + n);
  
  printf("%d\n", res);
  for(int i = 0; i < n; ++i) {
    whr = where(a[i].first, a[i].second);
    
    if(whr == 1) {
      printf("1 %d U\n", a[i].second);
      printf("1 %d R\n", a[i].first);
      puts("2");
      printf("1 %d D\n", a[i].second);
      printf("1 %d L\n", a[i].first);
      puts("3");
    } else if(whr == 2) {
      printf("1 %d U\n", a[i].second);
      printf("1 %d L\n", -a[i].first);
      puts("2");
      printf("1 %d D\n", a[i].second);
      printf("1 %d R\n", -a[i].first);
      puts("3");
    } else if(whr == 3) {
      printf("1 %d D\n", -a[i].second);
      printf("1 %d L\n", -a[i].first);
      puts("2");
      printf("1 %d U\n", -a[i].second);
      printf("1 %d R\n", -a[i].first);
      puts("3");
    } else if(whr == 4) {
      printf("1 %d D\n", -a[i].second);
      printf("1 %d R\n", a[i].first);
      puts("2");
      printf("1 %d U\n", -a[i].second);
      printf("1 %d L\n", a[i].first);
      puts("3");
    } else if(whr == 5) {
      if(a[i].second > 0) {
        printf("1 %d U\n", a[i].second);
        puts("2");
        printf("1 %d D\n", a[i].second);
        puts("3");
      } else {
        printf("1 %d D\n", -a[i].second);
        puts("2");
        printf("1 %d U\n", -a[i].second);
        puts("3");
      }
    } else if(whr == 6) {
      if(a[i].first > 0) {
        printf("1 %d R\n", a[i].first);
        puts("2");
        printf("1 %d L\n", a[i].first);
        puts("3");
      } else {
        printf("1 %d L\n", -a[i].first);
        puts("2");
        printf("1 %d R\n", -a[i].first);
        puts("3");
      }
    }
  }
  
  return 0;
}
