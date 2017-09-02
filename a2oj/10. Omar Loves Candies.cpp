#include <stdio.h>
#include <algorithm>

using namespace std;

int const N = 1e3 + 1, oo = 2e9 + 1;
int n, m, g[N][N], cs[N][N];

int main() {
    int t;
    scanf("%d", &t);
    while(t-- != 0) {
        scanf("%d %d", &n, &m);
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                scanf("%d", &g[i][j]);

        int res = -oo;

        for(int i = n - 1; i >= 0; --i)
            for(int j = m - 1; j >= 0; --j) {
                cs[i][j] = g[i][j];
                if(i != n - 1) cs[i][j] += cs[i+1][j];
                if(j != m - 1) cs[i][j] += cs[i][j+1];
                if(i != n - 1 && j != m - 1) cs[i][j] -= cs[i+1][j+1];

                res = max(res, cs[i][j]);
            }

        printf("%d\n", res);
    }

    return 0;
}

