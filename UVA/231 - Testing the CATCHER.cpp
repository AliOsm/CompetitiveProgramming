#include <stdio.h>
#include <vector>
#include <memory.h>
#include <algorithm>

using namespace std;

vector<int> arr;
int dp[32768];
int n;

int calc(int i) {
    int &res = dp[i];
    if(res != -1) return res;
    
    res = 0;
    for(int j = i + 1; j < n; j++)
        if(arr[j] < arr[i])
            res = max(res, calc(j) + 1);
    
    return dp[i] = res;
}

int main() {
    int res = 0, tmp = 0, c = 1;
    
    while(true) {
        while(true) {
            scanf("%i", &tmp);
            if(tmp == -1) break;
            arr.push_back(tmp);
        }
        n = arr.size();
        
        memset(dp, -1, sizeof dp);
        res = 0;
        for(int i = 0; i < arr.size(); i++)
            res = max(res, calc(i) + 1);
        printf("Test #%i:\n  maximum possible interceptions: %i\n", c++, res);
        
        scanf("%i", &tmp);
        if(tmp == -1) break;
        putchar('\n');
        arr.clear();
        arr.push_back(tmp);
    }
    
    return 0;
}
