#include <iostream>

using namespace std;

int main() {
    int x;

    cin >> x;

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < x; j++) {
            if (i >= j)
                cout << '*';
        }

        cout << endl;
    }

    return 0;
}
