#include <iostream>
#include <cmath>

using namespace std;

int board[5][5];

int main() {
    int x, y;
    
    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++) {
            cin >> board[i][j];
            
            if(board[i][j] == 1) {
                x = i;
                y = j;
            }
        }
    
    cout << abs(2 - x) + abs(2 - y) << endl;

    return 0;
}
