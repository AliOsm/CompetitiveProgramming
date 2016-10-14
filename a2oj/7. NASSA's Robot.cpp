#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n, miX, miY, maX, maY;
    string s;
    vector<string> arr;

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> s;
        arr.push_back(s);
    }

    for (int i = 0; i <= n - 1; i++) {
        miX = miY = maX = maY = 0;
        
        for (int j = 0; j <= arr[i].size() - 1; j++) {
            switch (arr[i][j]) {
                case 'R':
                    maX++; miX++; break;
                case 'L':
                    miX--; maX--; break;
                case 'U':
                    maY++; miY++; break;
                case 'D':
                    miY--; maY--; break;
                default:
                    maX++;
                    miX--;
                    maY++;
                    miY--;
            }
        }

        cout << miX << ' ' << miY << ' ' << maX << ' ' << maY << endl;
    }

    return 0;
}
