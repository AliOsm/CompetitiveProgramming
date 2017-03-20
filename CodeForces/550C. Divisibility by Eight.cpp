#include <iostream>
#include <string>
#include <memory.h>

using namespace std;

string s;
bool dp[101][1001];

bool calc(int i, int number) {
    if(number % 8 == 0 && number != 0) {
      cout << "YES" << endl;
      cout << number << endl;
      exit(0);
    }
    
    if(i == s.length()) return 0;
    if(!dp[i][number]) return 0;
    
    calc(i + 1, number);
    calc(i + 1, ((number * 10) + (s[i] - '0')) % 1000);
    
    return dp[i][number] = 0;
}

int main() {
    cin >> s;
    
    if(s.find('0') != string::npos) {
      cout << "YES" << endl << 0 << endl;
      return 0;
    }
    
    memset(dp, 1, sizeof dp);
    if(!calc(0, 0))
        cout << "NO" << endl;
    
    return 0;
}

