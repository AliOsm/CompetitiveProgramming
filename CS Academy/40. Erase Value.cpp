#include <stdio.h>
#include <algorithm>

using namespace std;

int n, freq[1001];

int main() {
    scanf("%d", &n);
    int total = 0;
    for(int i = 0, tmp; i < n; ++i) {
        scanf("%d", &tmp);
        total += tmp;
        ++freq[tmp];
    }
    
    int res = 1e7;
    for(int i = 0; i < 1001; ++i)
        res = min(res, total - (freq[i] * i));
    
    printf("%d\n", res);
    
    return 0;
}
