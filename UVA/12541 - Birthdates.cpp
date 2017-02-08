#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct person {
    int d, m, y;
    string s;
    
    inline bool operator<(const person &p) const {
        if(y != p.y) return y < p.y;
        if(m != p.m) return m < p.m;
        return d < p.d;
    }
};

vector<person> arr;

int main() {
    int n;
    cin >> n;
    
    arr.resize(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i].s >> arr[i].d >> arr[i].m >> arr[i].y;
    
    sort(arr.begin(), arr.end());
    
    cout << arr[n-1].s << endl;
    cout << arr[0].s << endl;
    
    return 0;
}
