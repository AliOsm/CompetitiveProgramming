#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> ppl;

int main() {
    int n;
    cin >> n;
    
    ppl.resize(n);
    for(int i = 0; i < n; i++) cin >> ppl[i];
    
    string words[] = {"Happy", "birthday", "to", "you"};
    if(n <= 16) {
        int cnt = 0;
        for(int i = 0; i < 16; i++) {
            cout << ppl[i % n] << ": " << ((cnt + 1) % 3 == 0 && (i) % 4 == 3 ? "Rujia" : words[i % 4]) << endl;
            
            if((i + 1) % 4 == 0) cnt++;
        }
    } else {
        int cnt = 1;
        for(int i = 0, j = 0; i < n || (cnt - 1) % 4 != 0;) {
            cout << ppl[i++ % n] << ": " << words[i % 4] << endl;
            cout << ppl[i++ % n] << ": " << words[i % 4] << endl;
            cout << ppl[i++ % n] << ": " << words[i % 4] << endl;
            
            if(cnt == 4 * j + 3) {
                cout << ppl[i++ % n] << ": " << "Rujia" << endl;
                j++;
            } else
                cout << ppl[i++ % n] << ": " << words[i % 4] << endl;
            
            cnt++;
        }
    }
    
    return 0;
}
