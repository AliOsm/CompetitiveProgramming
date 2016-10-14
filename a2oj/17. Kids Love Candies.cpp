#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, max, candies, tmp, counter;
    vector<int> candiesNum, results;

    cin >> n;

    while (n > 0) {
        counter = 0;
        candiesNum.clear();
        cin >> candies >> max;

        for (int i = 1; i <= candies; i++) {
            cin >> tmp;
            candiesNum.push_back(tmp);
        }

        for (int i = 0; i <= candies - 1; i++) {
            counter += candiesNum[i] / max;
        }

        results.push_back(counter);

        n--;
    }

    for (int i = 0; i <= results.size() - 1; i++) {
        cout << results[i] << endl;
    }

        return 0;
}
