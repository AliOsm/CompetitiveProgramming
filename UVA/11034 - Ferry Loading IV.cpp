#include <iostream>
#include <string>
#include <queue>
 
using namespace std;
 
queue<double> l, r;
 
int main() {
    int t, m, tmp, res;
    double n, w;
    string s;
 
    cin >> t;
 
    while(t--) {
        cin >> n >> m;
 
        while(!l.empty()) l.pop();
        while(!r.empty()) r.pop();
        res = 0;
 
        while(m--) {
            cin >> tmp >> s;
 
            if(s == "left") l.push(tmp / 100.0);
            else r.push(tmp / 100.0);
        }
 
        while(!l.empty() || !r.empty()) {
            w = 0;
            if(!r.empty() || !l.empty()) res++;
            else break;
 
            while(!l.empty())
                if(w + l.front() <= n) {
                    w += l.front();
                    l.pop();
                } else break;
 
            w = 0;
 
            if(!r.empty() || !l.empty()) res++;
            else break;
 
            while(!r.empty())
                if(w + r.front() <= n) {
                    w += r.front();
                    r.pop();
                } else break;
        }
 
        cout << res << endl;
    }
 
    return 0;
}
