#include <iostream>
#include <string>

using namespace std;

int main() {
    int n, t, sum, tmp;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> t;
        sum = 0;

        while (t--) {
            cin >> tmp;
            sum += tmp;
        }

        cout << "Case " << i << ": " << sum << endl;
    }

    return 0;
}
