#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<pair<int, string> > arr;

int main() {
    int n, tmp;
    string s;
    cin >> n;
    
    while(n--) {
        cin >> tmp >> s;
        arr.push_back(make_pair(tmp, s));
    }
    
    if(arr[arr.size()-1].second != "North" || arr[0].second != "South") {
        cout << "NO" << endl;
        return 0;
    }
    
    int x = 0, in = 1;
    
    for(int i = 0; i < arr.size(); i++) {
        if(in == 1 && arr[i].second != "South") {
            cout << "NO" << endl;
            return 0;
        }
        
        if(in == 2 && arr[i].second != "North") {
            cout << "NO" << endl;
            return 0;
        }
        
        if(arr[i].second == "North")
            x -= arr[i].first;
        
        if(arr[i].second == "South")
            x += arr[i].first;
        
        if(x > 20000 || x < 0) {
            cout << "NO" << endl;
            return 0;
        }
        
        if(x == 0) in = 1;
        else if(x == 20000) in = 2;
        else in = 3;
    }
    
    if(x == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
    
    return 0;
}
