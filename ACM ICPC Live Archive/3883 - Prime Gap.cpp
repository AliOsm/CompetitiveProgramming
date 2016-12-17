#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int const N = 2 * 1e6 + 1;
bool bPrime[N];
vector<int> iPrime;

void sieve() {
    for (int p = 2; p <= N; p++)
        if (bPrime[p] == false) {
            iPrime.push_back(p);
            for (int i = p * 2; i <= N; i += p)
                bPrime[i] = true;
        }
}

int main() {
    bPrime[0] = true;
    bPrime[1] = true;
    sieve();

    int n, tmp;
    
    while(cin >> n && n) {
        if(!bPrime[n]) cout << 0 << endl;
        else {
            tmp = lower_bound(iPrime.begin(), iPrime.end(), n) - iPrime.begin();
            cout << iPrime[tmp] - iPrime[tmp - 1] << endl;
        }
    }
    
    return 0;
}
