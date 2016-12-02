#include <stdio.h>
#include <algorithm>
#include <vector>
#include <memory.h>
 
using namespace std;
 
vector<pair<int, int> > p;
int const N = 1e4 + 1;
int dp[N][N];
int n;
 
int calc(int i) {
    int &res = dp[p[i].first][p[i].second];
    if(res != -1) return res;
 
    res = 0;
    for(int j = 0; j < n; j++)
        if(p[i].first < p[j].first && p[i].second > p[j].second)
            res = max(res, calc(j) + 1);
    return res;
}

void build_path(int i) {
	int res = 0, tmp = 0;
	int index = -1;
	printf("%i\n", i + 1);
	
	for(int j = 0; j < n; j++)
		if(p[i].first < p[j].first && p[i].second > p[j].second) {
			tmp = dp[p[i].first][p[i].second];
			if(tmp >= res) {
				res = tmp;
				index = j;
			}
		}
	
	if(index != -1) build_path(index);
}

int main() {
    int a, b;
 
    while(scanf("%i %i", &a, &b) > 0)
        p.push_back(make_pair(a, b));
    n = p.size();
 
    memset(dp, -1, sizeof dp);
 
    int res = 0, tmp = 0, res_index = 0;
    for(int i = 0; i < n; i++) {
        tmp = calc(i) + 1;
        if(tmp > res) {
        	res = tmp;
        	res_index = i;
        }
    }
 
    printf("%i\n", res);
    build_path(res_index);
    
    return 0;
}
