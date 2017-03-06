#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int const N = 1e6 + 1;
int n, m;
int nums[N], ds[N], sols[N];
vector<vector<int> > vals, poss;

int find(int x) {
    return (ds[x] == x ? x : (ds[x] = find(ds[x])));
}

int main() {
    cin >> n >> m;
    
    for(int i = 0; i < n; i++) {
        ds[i] = i;
        cin >> nums[i];
    }
    
    int a, b;
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        a--; b--;
        
        ds[find(a)] = find(b);
    }
    
    vals.resize(n);
    poss.resize(n);
    
    for(int i = 0; i < n; i++) {
        vals[find(i)].push_back(nums[i]);
        poss[find(i)].push_back(i);
    }
    
    for(int i = 0; i < n; i++) {
        sort(vals[i].rbegin(), vals[i].rend());
        
        for(int j = 0; j < poss[i].size(); j++)
            sols[poss[i][j]] = vals[i][j];
    }
    
    for(int i = 0; i < n; i++)
        cout << (i == 0 ? "" : " ") << sols[i];
    cout << endl;
    
    return 0;
}
