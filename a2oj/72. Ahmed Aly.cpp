#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n;
    int x, y, z;
    char c1, c2;

    cin >> n;

    vector<string> arr(n);

    for (int i = 1; i <= n; i++) {
        cin >> x >> c1 >> y >> c2 >> z;

        if (c1 == '-') {
            if (x - y == z)
                arr[i - 1] = "YES";
            else
                arr[i - 1] = "NO";
        }
        else if (c1 == '+') {
            if (x + y == z)
                arr[i - 1] = "YES";
            else
                arr[i - 1] = "NO";
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << "Case " << i << ": " << arr[i - 1] << endl;
    }

    return 0;
}
