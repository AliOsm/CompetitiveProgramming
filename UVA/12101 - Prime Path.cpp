#include <stdio.h>
#include <memory.h>
#include <vector>
#include <queue>

int const N = 1e4 + 1;

bool prime[N];
std::vector<int> primes;
void sieve() {
  memset(prime, true, sizeof prime);
  prime[0] = prime[1] = false;
  
  for(int i = 2; i * i < N; ++i)
    if(prime[i])
      for(int j = i * i; j < N; j += i)
        prime[j] = false;
  
  for(int i = 1000; i < N; ++i)
    if(prime[i])
      primes.push_back(i);
}

bool diff(int p1, int p2) {
  int sim = 0;
  for(int k = 0; k < 4; ++k) {
    if(p1 % 10 == p2 % 10)
      ++sim;
    p1 /= 10;
    p2 /= 10;
  }
  return sim == 3;
}

std::vector<std::vector<int> > g(N);
void buildGraph() {
  for(int i = 0; i < (int)primes.size(); ++i)
    for(int j = 0; j < (int)primes.size(); ++j)
      if(i != j && diff(primes[i], primes[j]) == 1)
        g[primes[i]].push_back(primes[j]);
}

bool vis[N];
std::queue<int> q;
int BFS(int src, int dst) {
  memset(vis, false, sizeof vis);
  while(!q.empty()) q.pop();
  q.push(src);
  
  int cost = 0, size, fr;
  while(!q.empty()) {
    int size = q.size();
    
    while(size-- != 0) {
      fr = q.front();
      q.pop();
      
      vis[fr] = true;
      
      if(fr == dst)
        return cost;
      
      for(int i = 0; i < (int)g[fr].size(); ++i)
        if(!vis[g[fr][i]])
          q.push(g[fr][i]);
    }
    
    ++cost;
  }
  
  return -1;
}

int main() {
  sieve();
  buildGraph();
  
  int t;
  scanf("%d", &t);
  
  int a, b, res;
  while(t-- != 0) {
    scanf("%d %d", &a, &b);
    
    res = BFS(a, b);
    
    if(res == -1)
      puts("Impossible");
    else
      printf("%d\n", res);
  }
  
  return 0;
}

