#include <iostream>

using namespace std;

int main() {
    int i, space, rows, k = 0;
    cin >> rows;

    for(i = 1; i <= rows; ++i) {
        for(space = 1; space <= rows - i; ++space) {
           cout << " ";
        }

        while(k != 2 * i - 1) {
           cout << "*";
           ++k;
        }

        k = 0;
        cout << "\n";
    }

    return 0;
}
