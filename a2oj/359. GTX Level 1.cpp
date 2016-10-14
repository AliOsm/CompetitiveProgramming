#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;

    cin >> n;

    vector<int> arr(n);

    while (--n >= 0) {
        cin >> arr[n];
    }

    sort(arr.begin(), arr.end());

    cout << arr[0] << ' ' << arr[1] << endl;

    return 0;
}