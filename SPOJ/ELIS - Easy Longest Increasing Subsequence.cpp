#include <stdio.h>
#include <algorithm>
#include <memory.h>

using namespace std;

int arr[11], dp[11];
int n;

int calc(int i) {
    int &res = dp[i];
    
    if(res != -1) return res;
    
    res = 0;
    for(int j = i + 1; j < n; j++)
        if(arr[i] < arr[j])
            res = max(res, calc(j) + 1);
    
    return res;
}

int main() {
    scanf("%i", &n);
    for(int i = 0; i < n; i++) scanf("%i", &arr[i]);
    
    memset(dp, -1, sizeof dp);
    
    int res = 0;
	for(int i = 0; i < n; i++) res = max(res, calc(i) + 1);
    printf("%i\n", res);
    
    return 0;
}
