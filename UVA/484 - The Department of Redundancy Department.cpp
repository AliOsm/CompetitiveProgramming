#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int n;
    map<int, pair<int, int> > mp;
    
    int i = 0;
    while(cin >> n)
        if(mp.count(n)) mp[n].second++;
        else {
            mp[n] = make_pair(i, 1);
            i++;
        }
    
    vector<pair<int, int> > arr(mp.size());
    
    for(map<int, pair<int, int> >::iterator it = mp.begin(); it != mp.end(); it++)
        arr[(*it).second.first] = make_pair((*it).first, (*it).second.second);
    
    for(int i = 0; i < arr.size(); i++)
        cout << arr[i].first << ' ' << arr[i].second << endl;
	
	return 0;
}
