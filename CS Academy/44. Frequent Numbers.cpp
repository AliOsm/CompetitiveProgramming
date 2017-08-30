#include <stdio.h>

using namespace std;

int n, k, arr[1001];

int main() {
    scanf("%d %d", &n, &k);
    for(int i = 0, tmp; i < n; ++i) {
        scanf("%d", &tmp);
        ++arr[tmp];
    }
    
    int res = 0;
    for(int i = 0; i < 1001; ++i)
        res += arr[i] >= k;
    
    printf("%d\n", res);
    
    return 0;
}
