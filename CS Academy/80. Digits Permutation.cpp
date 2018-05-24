/*
    Idea:
        - sort number `a` and try all permutations of it.
*/

#include <bits/stdc++.h>

using namespace std;

int a, b;
vector<int> all;

long long toInt() {
    if(all[0] == 0)
        return 2e9;
    long long ret = 0;
    for(int i = 0; i < all.size(); ++i)
        ret *= 10ll, ret += all[i];
    return ret;
}

int main() {
    cin >> a >> b;
    while(a != 0) {
        all.push_back(a % 10);
        a /= 10;
    }
    sort(all.begin(), all.end());
    
    long long res = -1;
    do {
        long long cur = toInt();
        if(cur <= b && cur > res)
            res = cur;
    } while(next_permutation(all.begin(), all.end()));
    
    cout << res << endl;
    
    return 0;
}
