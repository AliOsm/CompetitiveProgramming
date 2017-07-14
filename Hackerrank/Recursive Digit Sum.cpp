#include <iostream>
#include <string>

using namespace std;

string n;
int k, res;

int toInt() {
    int tmp = 0;
    for(int i = 0; i < n.length(); ++i)
        tmp += (n[i] - '0');
    return tmp;
}

void stringSum() {
    int tmp = 0;
    for(int i = 0; i < n.length(); ++i)
        tmp += (n[i] - '0');
    
    n = "";
    while(tmp != 0) {
        n += ((tmp % 10) + '0');
        tmp /= 10;
    }
}

void stringRec() {
    stringSum();
    if(n.length() == 1) return;
    stringRec();
}

void intSum() {
    int tmp = 0;
    while(res != 0) {
        tmp += (res % 10);
        res /= 10;
    }
    res = tmp;
}

void intRec() {
    intSum();
    if(res < 10) return;
    intRec();
}

int main() {
    cin >> n >> k;
    stringRec();
    res = toInt() * k;
    intRec();
    cout << res << endl;
    
    return 0;
}
