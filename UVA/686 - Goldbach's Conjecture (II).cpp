#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
#include <set>

using namespace std;

int const N = 32769;
bool bPrimes[N];
vector<int> iPrimes;
set<pair<int, int> > res;

void sieve() {
    memset(bPrimes, true, sizeof bPrimes);
    
    bPrimes[0] = false;
    bPrimes[1] = false;
    
    for(int i = 2; i < N; i++)
        if(bPrimes[i]) {
            iPrimes.push_back(i);
            for(int j = i + i; j < N; j += i)
                bPrimes[j] = false;
        }
}

int main() {
    int n, c;
    
    sieve();
    
    while(cin >> n && n) {
        res.clear();
        c = 0;
        
        for(int i = 0; i < iPrimes.size(); i++)
            if(binary_search(iPrimes.begin(), iPrimes.end(), n - iPrimes[i]) && bPrimes[n - iPrimes[i]])
                if(iPrimes[i] > n - iPrimes[i])
                    res.insert(make_pair(n - iPrimes[i], iPrimes[i]));
                else
                    res.insert(make_pair(iPrimes[i], n - iPrimes[i]));

        cout << res.size() << endl;
    }
    
    return 0;
}
