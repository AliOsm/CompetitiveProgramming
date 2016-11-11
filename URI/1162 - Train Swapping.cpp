#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
    	int n;
    	cin >> n;
    	
    	arr.clear();
    	arr.resize(n);
    	
    	for(int i = 0; i < n; i++) cin >> arr[i];
    	
    	int c = 0;
    	for(int i = 0; i < n; i++)
    		for(int j = i + 1; j < n; j++)
    			if(arr[i] > arr[j]) {
    				int tmp = arr[i];
    				arr[i] = arr[j];
    				arr[j] = tmp;
    				c++;
    			}
    	
    	cout << "Optimal train swapping takes " << c << " swaps." << endl;
    }
    
    return 0;
}
