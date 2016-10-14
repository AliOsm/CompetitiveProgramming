#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    int n, x, y;

    while (t--) {
        cin >> n >> x >> y;

        vector<int> arr(n);

        while (--n >= 0) {
            cin >> arr[n];
        }

        if (arr[0] == y && arr[arr.size() - 1] == x)
            cout << "BOTH" << endl;
        else if (arr[0] == y && arr[arr.size() - 1] != x)
            cout << "HARD" << endl;
        else if (arr[0] != y && arr[arr.size() - 1] == x)
            cout << "EASY" << endl;
        else
            cout << "OKAY" << endl;
    }

    return 0;
}
