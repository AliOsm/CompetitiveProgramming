#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int arr[100002];

int main() {
    int n, a, tmp;
    cin >> n >> a;
    tmp = a;
    
    for(int i = 0; i < n; i++) cin >> arr[i];
    arr[n++] = a;
    sort(arr, arr + n);
    
    int t1 = abs(a - arr[0]) * 2 + abs(a - arr[n - 2]);
    int t2 = abs(a - arr[1]) * 2 + abs(a - arr[n - 1]);
    int t3 = abs(a - arr[n - 1]) * 2 + abs(a - arr[1]);
    int t4 = abs(a - arr[n - 2]) * 2 + abs(a - arr[0]);
    
    cout << min(t1, min(t2, min(t3, t4))) << endl;
    
    return 0;
}
