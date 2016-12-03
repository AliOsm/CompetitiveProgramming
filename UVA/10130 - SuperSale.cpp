#include <stdio.h>
#include <vector>
#include <memory.h>
#include <algorithm>

using namespace std;

vector<pair<int, int> > items;
vector<int> persons;
int dp[1000][1000];
int n, m;

int calc(int i, int c) {
    if(i == n) return 0;
    if(dp[i][c] != -1) return dp[i][c];
    
    int res1 = 0, res2 = 0;
    if(c >= items[i].second) res1 = calc(i + 1, c - items[i].second) + items[i].first;
    res2 = calc(i + 1, c);
    return dp[i][c] = max(res1, res2);
}

int main() {
    int t, a, b;
    scanf("%i", &t);
    
    while(t--) {
        items.clear();
        persons.clear();
        memset(dp, -1, sizeof(dp));
        
        scanf("%i", &n);
        
        for(int i = 0; i < n; i++) {
            scanf("%i %i", &a, &b);
            items.push_back(make_pair(a, b));
        }
        
        scanf("%i", &m);
        persons.resize(m);
        for(int i = 0; i < m; i++) scanf("%i", &persons[i]);
        
        int res = 0, total = 0;
        for(int i = 0; i < m; i++)
            total += calc(0, persons[i]);
        
        printf("%i\n", total);
    }
    
    return 0;
}
