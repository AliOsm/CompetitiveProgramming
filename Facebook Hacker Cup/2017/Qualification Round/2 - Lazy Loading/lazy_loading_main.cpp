#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        int m;
        cin >> m;

        vector<int> arr(m);

        for(int j = 0; j < m; j++) cin >> arr[j];
        sort(arr.begin(), arr.end());

        int d = 0;

        while(!arr.empty()) {
            int c = arr[arr.size() - 1], k = 1;
            arr.pop_back();

            if((c * k) >= 50) d++;
            else {
                while((c * k) < 50 && !arr.empty()) {
                    k++;
                    arr.erase(arr.begin());
                }

                if(c * k >= 50) d++;
            }
        }

        cout << "Case #" << i << ": " << d << endl;
    }

    return 0;
}
