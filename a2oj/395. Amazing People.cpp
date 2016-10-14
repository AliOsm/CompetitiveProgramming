#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t, x;
    vector<int> numArr;

    cin >> t;

    for (int i = 1; i <= t; i++) {
        cin >> x;
        numArr.push_back(x);
    }

    for (int i = 0; i <= t - 1; i++) {
        cout << "Case " << i + 1 << ":" << endl;

        if (numArr[i] > 0 && numArr[i] < 6)
            cout << "Languages" << endl;
        else if (numArr[i] > 5 && numArr[i] < 8)
            cout << "Read and Write" << endl;
        else if (numArr[i] > 7 && numArr[i] < 13)
            cout << "Robotics" << endl;
        else if (numArr[i] > 12 && numArr[i] < 20)
            cout << "Programming and Robotics" << endl;
        else
            cout << "Read about everything" << endl;
    }

    return 0;
}
