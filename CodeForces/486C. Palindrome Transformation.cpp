#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;

int const N = 1e5 + 1;
int n, p, res;
char s[N];
bool diff[N];

void calc(int st, int en) {
  int l = 1e9, r = 1e9;
  for(int i = st; i <= p; i++)
    if(!diff[i]) {
      l = i;
      break;
    }
  for(int i = en; i >= p; i--)
    if(!diff[i]) {
      r = i;
      break;
    }

  if(l == 1e9 && r == 1e9) {
    res = 0;
    return;
  } else if(l == 1e9) {
    l = p;
    res += r - p;
  } else if(r == 1e9) {
    r = p;
    res += p - l;
  } else {
    res += min(p - l, r - p) + (r - l);
  }

  for(int i = l; i <= r; i++)
    if(!diff[i])
      res += min(abs(s[i] - s[n - i + 1]), min(abs(s[i] - 'a') + abs(s[n - i + 1] - 'z') + 1, abs(s[i] - 'z') + abs(s[n - i + 1] - 'a') + 1));
}

int main() {
  scanf("%d%d", &n, &p);
  scanf("%s", s);
  for(int i = n; i > 0; i--)
    s[i] = s[i - 1];

  for(int i = 1, j = n; i < j; i++, j--)
    if(s[i] == s[j])
      diff[i] = diff[j] = true;

  int mid = n / 2;
  if(n % 2 == 0) {
    (p > mid) ? calc(mid + 1, n) : calc(1, mid);
  } else {
    diff[mid + 1] = true;
    (p >= mid) ? calc(mid + 2, n) : calc(1, mid);
  }

  printf("%d\n", res);

  return 0;
}

