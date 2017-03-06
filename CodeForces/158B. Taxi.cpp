#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, c = 0, arr[4] = {0};
    cin >> n;

    for(int i = 0; i < n; i++) {
    	int tmp;
    	cin >> tmp;

    	if(tmp == 4)
    		c++;
    	else
    		arr[tmp]++;
    }

    while(arr[1] || arr[2] || arr[3]) {
    	if(arr[1] && arr[3]) {
    		arr[1]--;
    		arr[3]--;
    	} else if(arr[1] >= 2 && arr[2]) {
    		arr[1] -= 2;
    		arr[2]--;
    	} else if(arr[2] >= 2) {
    		arr[2] -= 2;
    	} else if(arr[1] >= 4) {
    		arr[1] -= 4;
    	} else if(arr[1] && arr[2]) {
    		arr[1]--;
    		arr[2]--;
    	} else if(arr[1] >= 3) {
    		arr[1] -= 3;
    	} else if(arr[3]) {
    		arr[3]--;
    	} else if(arr[2]) {
    		arr[2]--;
    	} else if(arr[1] >= 2) {
    		arr[1] -= 2;
    	} else {
    		arr[1]--;
    	}
    	
    	c++;
    }

    cout << c << endl;

    return 0;
}
