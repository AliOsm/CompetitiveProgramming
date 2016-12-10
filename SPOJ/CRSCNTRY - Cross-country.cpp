#include <stdio.h>
#include <memory.h>
#include <algorithm>

using namespace std;

int const N = 2001;
int n, m, dp[N][N], agnes[N], tom[N];

int calc(int i, int j) {
    if(i == n || j == m) return 0;
    
    int &res = dp[i][j];
    if(res != -1) return res;
    
    if(agnes[i] == tom[j])
        return res = calc(i + 1, j + 1) + 1;
    
    return res = max(calc(i + 1, j), calc(i, j + 1));
}

int main() {
    int t, tmp, res;
    scanf("%i", &t);
    
    while(t--) {
        res = 0;
        for(n = 0; scanf("%i", &tmp) && tmp; n++) agnes[n] = tmp;
        
        while(scanf("%i", &tmp) && tmp) {
            tom[0] = tmp;
            for(m = 1; scanf("%i", &tmp) && tmp; m++) tom[m] = tmp;
            
            memset(dp, -1, sizeof dp);
            res = max(res, calc(0, 0));
        }
        
        printf("%i\n", res);
    }
    
    return 0;
}
