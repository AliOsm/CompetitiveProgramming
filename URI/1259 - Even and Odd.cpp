#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> e;
vector<int> o;

int main() {
    int n;
    cin >> n;
    
    while(n--) {
    	int tmp;
    	cin >> tmp;
    	
    	if(tmp % 2 == 0)
    		e.push_back(tmp);
    	else
    		o.push_back(tmp);
    }
    
    sort(e.begin(), e.end());
    sort(o.begin(), o.end());
    reverse(o.begin(), o.end());

    for(int i = 0, len = e.size(); i < len; i++)
    	cout << e[i] << endl;
    	
    for(int i = 0, len = o.size(); i < len; i++)
    	cout << o[i] << endl;
    
    return 0;
}
