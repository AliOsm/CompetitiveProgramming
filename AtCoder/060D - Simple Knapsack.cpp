#include <stdio.h>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;

int const N = 101;
long long n, w;
long long dp[N][10000];
vector<pair<long long, long long> > a;
     
long long calc(int index, long long sum) {
    if(index == n) return 0;
    if(dp[index][int(sum % 10000)] != -1) return dp[index][int(sum % 10000)];
      
    long long res1 = 0, res2 = 0;
    if(sum >= a[index].first) res1 = calc(index + 1, sum - a[index].first) + a[index].second;
    res2 = calc(index + 1, sum);
    return dp[index][int(sum % 10000)] = max(res1, res2);
}
     
int main() {
    scanf("%d%d", &n, &w);
    a.resize(n);
    for(int i = 0; i < n; ++i)
        scanf("%d%d", &a[i].first, &a[i].second);
    	
    memset(dp, -1, sizeof dp);
    printf("%lld\n", calc(0, w));
     
    return 0;
}
