#include <stdio.h>
#include <memory.h>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair<int, vector<int> > > paths;
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

void path(int i, int j, int index) {
    if(i == n || j == m) return;
    
    int a = 0, b = 0, c = 0;
    
    if(agnes[i] == tom[j])
        a = calc(i + 1, j + 1) + 1;
    
    b = calc(i + 1, j);
    c = calc(i, j + 1);
    
    if(a == calc(i, j)) {
        paths[index].second.push_back(agnes[i]);
        path(i + 1, j + 1, index);
    } else if(b == calc(i, j))
        path(i + 1, j, index);
    else
        path(i, j + 1, index);
}

int main() {
    int t, tmp, res;
    scanf("%i", &t);
    
    while(t--) {
        res = 0;
        paths.clear();
        paths.resize(N);
        for(n = 0; scanf("%i", &tmp) && tmp; n++) agnes[n] = tmp;
        
        for(int i = 0; scanf("%i", &tmp) && tmp; i++) {
            tom[0] = tmp;
            for(m = 1; scanf("%i", &tmp) && tmp; m++) tom[m] = tmp;
            
            memset(dp, -1, sizeof dp);
            tmp = calc(0, 0);
            res = max(res, tmp);
            paths[i].first = tmp;
            path(0, 0, i);
        }
        
        printf("%i -> ", res);
        sort(paths.begin(), paths.end());
        for(int i = 0, len1 = paths.size() - 1, len2 = paths[len1].second.size(); i < len2; i++) {
            printf("%i", paths[len1].second[i]);
            if(i < len2 - 1) putchar(' ');
        }
        putchar('\n');
    }
    
    return 0;
}
