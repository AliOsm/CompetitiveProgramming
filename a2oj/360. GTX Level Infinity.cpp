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

    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << endl;
    }

    return 0;
}
