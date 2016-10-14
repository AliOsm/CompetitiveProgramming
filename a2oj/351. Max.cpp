#include <iostream>

using namespace std;

int larger(int x, int y) {
    if (x > y)
        return x;

    return y;
}

int main() {
    int x, y, z;

    cin >> x >> y >> z;

    cout << larger(x, larger(y, z)) << endl;

    return 0;
}
