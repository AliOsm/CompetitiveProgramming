#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr;

int main() {
    int n = -1, q = -1, c = 1;
    
    while(true) {
    	cin >> n >> q;
    	
    	if(n == 0 && q == 0) break;
    	
    	arr.clear();
    	arr.resize(n);
    	
    	for(int i = 0; i < n; i++)
    		cin >> arr[i];
    	
    	sort(arr.begin(), arr.end());
    		
    	cout << "CASE# " << c++ << ':' << endl;
    		
    	while(q--) {
    		int tmp;
    		cin >> tmp;
    		
    		int index = lower_bound(arr.begin(), arr.end(), tmp) - arr.begin();
    		
    		if(index < arr.size() && index >= 0 && arr[index] == tmp)
    			cout << tmp << " found at " << index + 1;
    		else
    			cout << tmp << " not found";
    		
    		cout << endl;
    	}
    }
    
    return 0;
}
