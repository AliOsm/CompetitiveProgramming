#include <stdio.h>
#include <algorithm>

using namespace std;

int n, k, a[101];

int rec(int i, int sum) {
    if(sum == k)
        return 0;
        
    if(i == n)
        return 1e5;
    
    return min(rec(i + 1, sum + a[i]) + 1, rec(i + 1, sum));
}

int main() {
    int t;
    scanf("%d", &t);
    while(t-- != 0) {
        scanf("%d %d", &n, &k);
        for(int i = 0; i < n; ++i)
            scanf("%d", a + i);
        
        int res = rec(0, 0);
        if(res >= 1e5)
            puts("impossible");
        else
            printf("%d\n", res);
    }
    
    return 0;
}
