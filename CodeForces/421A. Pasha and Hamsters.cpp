#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> ar, ax, arr;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    
    arr.resize(n);
    ar.resize(a);
    ax.resize(b);
    for(int i = 0; i < a; i++) cin >> ar[i];
    for(int i = 0; i < b; i++) cin >> ax[i];
    sort(ar.begin(), ar.end());
    sort(ax.begin(), ax.end());
    
    for(int i = 0; i < a; i++)
        arr[ar[i] - 1] = 1;
    
    for(int i = 0; i < b; i++)
        if(arr[ax[i] - 1] != 1)
            arr[ax[i] - 1] = 2;
    
    for(int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << endl;

	return 0;
}
