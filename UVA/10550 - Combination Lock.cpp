#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int init, st, nd, rd;
    
    while(cin >> init >> st >> nd >> rd && (init || st || nd || rd))
        cout << 1080 + (init > st ? ((init - st) * 9) : ((init - st + 40) * 9)) +
                       (nd > st ? ((nd - st) * 9) : ((nd - st + 40) * 9)) +
                       (nd > rd ? ((nd - rd) * 9) : ((nd - rd + 40) * 9)) << endl;
    
    return 0;
}
