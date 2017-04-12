#include <stdio.h> 
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;

int const N = 1e5 + 1;
int n, freq[N];
long long dp [N];

long long calc(int val) { 
    if(val >= N) return 0;
    
    long long &ret = dp[val];
    if(ret != -1) return ret;
    ret = 0;
    
    ret = max(ret, calc(val + 2) + (1LL * freq[val] * val));
    ret = max(ret, calc(val + 1));
    
    return ret;
}

int main() {
    scanf("%d", &n);
    int tmp;
    for(int i = 0; i < n; i++) {
        scanf("%d", &tmp);
	freq[tmp]++;
    }
    
    memset(dp, -1, sizeof dp);
    printf("%lld\n", calc(0));
    return 0;
}

