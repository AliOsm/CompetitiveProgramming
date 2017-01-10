#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;

double const PI = 3.1428571428571428571428571428571;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        int p, x, y;
        cin >> p >> x >> y;
        x -= 50;
        y -= 50;

        if(p == 0) {
            cout << "Case #" << i << ": white" << endl;
            continue;
        }

        if(p != 0 && x == 0 && y == 0) {
            cout << "Case #" << i << ": black" << endl;
            continue;
        }

        double theta, r;
        theta = (p / 100.0) * 360;
        r = sqrt(pow(0 - 0, 2.0) + pow(0 - 50, 2.0));

        if(x == 0 && y > 0) {
            if(sqrt(pow(0 - x, 2.0) + pow(0 - y, 2.0)) <= r && p != 0) cout << "Case #" << i << ": black" << endl;
            else cout << "Case #" << i << ": white" << endl;
            continue;
        }

        if(x == 0 && y < 0) {
            if(sqrt(pow(0 - x, 2.0) + pow(0 - y, 2.0)) <= r && theta >= 180) cout << "Case #" << i << ": black" << endl;
            else cout << "Case #" << i << ": white" << endl;
            continue;
        }

        if(x > 0 && y == 0) {
            if(sqrt(pow(0 - x, 2.0) + pow(0 - y, 2.0)) <= r && theta >= 90) cout << "Case #" << i << ": black" << endl;
            else cout << "Case #" << i << ": white" << endl;
            continue;
        }

        if(x < 0 && y == 0) {
            if(sqrt(pow(0 - x, 2.0) + pow(0 - y, 2.0)) <= r && theta >= 270)cout << "Case #" << i << ": black" << endl;
            else cout << "Case #" << i << ": white" << endl;
            continue;
        }

        if(sqrt(pow(0 - x, 2.0) + pow(0 - y, 2.0)) > r)
            cout << "Case #" << i << ": white" << endl;
        else {
            double ntheta = atan(1.0 * y / x) * 180 / PI;

            if(x >= 0 && y >= 0) {
                ntheta = 90 - ntheta;

                if(theta >= ntheta) cout << "Case #" << i << ": black" << endl;
                else cout << "Case #" << i << ": white" << endl;
            } else if(x <= 0 && y >= 0) {
                ntheta += 180;
                ntheta = 360 - ntheta + 90;

                if(theta >= ntheta) cout << "Case #" << i << ": black" << endl;
                else cout << "Case #" << i << ": white" << endl;
            } else if(x <= 0 && y <= 0) {
                ntheta += 180;
                ntheta = 360 - ntheta + 90;

                if(theta >= ntheta) cout << "Case #" << i << ": black" << endl;
                else cout << "Case #" << i << ": white" << endl;
            } else {
                ntheta += 360;
                ntheta = 360 - ntheta + 90;

                if(theta >= ntheta) cout << "Case #" << i << ": black" << endl;
                else cout << "Case #" << i << ": white" << endl;
            }
        }
    }

    return 0;
}
