#include <stdio.h>
#include <algorithm>

using namespace std;

int t, n, k, res;

int main() {
    scanf("%d", &t);
    
    while(t-- != 0) {
        scanf("%d %d", &n, &k);
        
        res = -1;
        for(int i = 1; i <= n; ++i)
            for(int j = i + 1; j <= n; ++j)
                res = max(res, i & j) < k ? max(res, i & j) : res;
            
        printf("%d\n", res);
    }
    
    return 0;
}

