#include <iostream>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <memory.h>

using namespace std;

const int N = 1e4 + 1;
int n, m, animals[101], dp[N][101];

int calc(int food, int animal) {
    if(animal == n) return 0;
    
    int &res = dp[food][animal];
    
    if(res != -1) return res;
    
    res = 0;
    if(food >= (n - animal) * animals[animal])
        res = max(res, calc(food - ((n - animal) * animals[animal]), animal + 1) + 1);

    return dp[food][animal] = max(res, calc(food, animal + 1));
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> animals[i];
    
    memset(dp, -1, sizeof dp);
    cout << calc(m, 0) << endl;
    
    return 0;
}
