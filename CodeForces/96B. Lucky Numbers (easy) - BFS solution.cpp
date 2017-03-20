#include <iostream>
#include <queue>

using namespace std;

struct SuperLucky {
    long long number;
    int fours, sevens;
};

void bfs(int des) {
    queue<SuperLucky> q;
    SuperLucky tmp;

    tmp.number = 4;
    tmp.fours = 1;
    tmp.sevens = 0;
    q.push(tmp);

    tmp.number = 7;
    tmp.fours = 0;
    tmp.sevens = 1;
    q.push(tmp);

    while (!q.empty()) {
        int size = q.size();

        while (size--) {
            SuperLucky fr = q.front();
            q.pop();

            fr.number *= 10;
            fr.number += 4;
            fr.fours++;

            if (fr.number >= des && fr.fours == fr.sevens) {
                cout << fr.number << endl;
                return;
            }

            q.push(fr);

            fr.number += 3;
            fr.fours--;
            fr.sevens++;

            if (fr.number >= des && fr.fours == fr.sevens) {
                cout << fr.number << endl;
                return;
            }

            q.push(fr);
        }
    }
}

int main() {
    int des;
    cin >> des;
    bfs(des);

    return 0;
}
