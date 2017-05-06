#include <stdio.h>
#include <vector>
#include <map>
#include <memory.h>

using namespace std;

int const N = 1e5 + 1;
int n, a, b, match[N];
bool vis[N];
vector<int> arr;
map<int, int> mp;

bool findMatch(int i) {
  vis[i] = true;
  
  if(arr[i] <= a && mp.count(a - arr[i]) &&
    (match[mp[a - arr[i]]] == -1 || !vis[match[mp[a - arr[i]]]] && findMatch(match[mp[a - arr[i]]]))) {
    match[mp[a - arr[i]]] = i;
    return true;
  }
  
  if(arr[i] <= b && mp.count(b - arr[i]) &&
    (match[mp[b - arr[i]]] == -1 || !vis[match[mp[b - arr[i]]]] && findMatch(match[mp[b - arr[i]]]))) {
    match[mp[b - arr[i]]] = i;
    return true;
  }
  
  return false;
}

int main() {
  scanf("%d%d%d", &n, &a, &b);
  
  arr.resize(n);
  for(int i = 0; i < n; ++i) {
    scanf("%d", &arr[i]);
    mp[arr[i]] = i;
  }
  
  memset(match, -1, sizeof match);
  for(int i = 0; i < n; ++i) {
    memset(vis, false, sizeof vis);
    
    if(!findMatch(i)) {
      puts("NO");
      return 0;
    }
  }
  
  puts("YES");
  
  for(int i = 0; i < n; ++i) {
    if(i) putchar(' ');
    
    if(arr[i] + arr[match[i]] == a) putchar('0');
    else putchar('1');
  }
  putchar('\n');
  
  return 0;
}

