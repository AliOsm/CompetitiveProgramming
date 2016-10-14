#include <iostream>

using namespace std;

int main() {
    int x;

    cin >> x;

    if (x < 1) {
        cout << "Don't be lazy, it takes only few minutes, you can do it." << endl;
    }
    else if (x == 1) {
        cout << "Good Job" << endl;
    }
    else {
        cout << "You Rocks Man" << endl;
    }

    return 0;
}
