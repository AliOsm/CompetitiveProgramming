#include <stdio.h>
#include <vector>
#include <memory.h>
#include <algorithm>

using namespace std;

vector<pair<int, int> > p;
int dp[2000][2000];
int n;

int calc(int i, int c) {
    if(i == n) return 0;
    if(dp[i][c] != -1) return dp[i][c];
    
    int res1 = 0, res2 = 0;
    if(c >= p[i].first) res1 = calc(i + 1, c - p[i].first) + p[i].second;
    res2 = calc(i + 1, c);
    return dp[i][c] = max(res1, res2);
}

int main() {
    int c, a, b;
    scanf("%i %i", &c, &n);
    
    memset(dp, -1, sizeof(dp));
    
    for(int i = 0; i < n; i++) {
        scanf("%i %i", &a, &b);
        p.push_back(make_pair(a, b));
    }
    
    printf("%i\n", calc(0, c));
    
    return 0;
}
