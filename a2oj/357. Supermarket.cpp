#include <iostream>
#include <string>

using namespace std;

int main() {
    long long n, s, cost, total = 0;

    cin >> n >> s;

    while (n > 0) {
        cin >> cost;
        total += cost;
        n--;
    }

    if (total <= s) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }

    return 0;
}
