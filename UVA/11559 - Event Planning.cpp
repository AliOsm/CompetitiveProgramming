#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long n, b, h, w;
    vector<long long> hb;
    
    while(cin >> n >> b >> h >> w) {
        long long fp = 1e18 + 1;
        bool can = false;
        
        for(int i = 0; i < h; i++) {
            long long p;
            cin >> p;
            
            hb.clear();
            hb.resize(w);
            for(int j = 0; j < w; j++)
                cin >> hb[j];
            
            for(int j = 0; j < w; j++)
                if(hb[j] >= n && p * n <= b && p * n < fp) {
                    fp = p * n;
                    can = true;
                    break;
                }
        }
        
        if(can) cout << fp << endl;
        else cout << "stay home" << endl;
    }
    
    return 0;
}
