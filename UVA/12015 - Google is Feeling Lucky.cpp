#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

vector<pair<int, string> > arr;

int main() {
    string s;
    int t, r;
    cin >> t;
    
    for(int i = 1; t--; i++) {
        cout << "Case #" << i << ":" << endl;
        arr.clear();
        
        for(int i = 0; i < 10; i++) {
            cin >> s >> r;
            arr.push_back(make_pair(r, s));
        }
        
        r = arr[0].first;
        for(int j = 0; j < 10; j++)
            if(r < arr[j].first)
                r = arr[j].first;
        
        for(int j = 0; j < 10; j++)
            if(arr[j].first == r)
                cout << arr[j].second << endl;
    }

	return 0;
}
