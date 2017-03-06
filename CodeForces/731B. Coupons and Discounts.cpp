#include <iostream>

using namespace std;

int arr[200001];

int main() {
    int c;
    cin >> c;
    
    for(int i = 0; i < c; i++) cin >> arr[i];
    
    for(int i = 0; i < c; i++)
    	if(arr[i] % 2 == 0)
    		continue;
    	else
    		if(arr[i + 1]-- == 0) {
    			cout << "NO" << endl;
    			return 0;
    		}
    
    cout << "YES" << endl;
    
    return 0;
}
