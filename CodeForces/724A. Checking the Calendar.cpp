#include <iostream>
#include <string>

using namespace std;

int main() {
	string days[7] = { "monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday" };
    string day1, day2;
    cin >> day1 >> day2;
    
    if(day1 == day2) {
    	cout << "YES" << endl;
    	return 0;
    }
    else
    	for(int i = 0; i < 7; i++)
    		if(days[i] == day1) {
    			if(days[(i+2) % 7] == day2 || days[(i+3) % 7] == day2) {
    				cout << "YES" << endl;
    				return 0;
    			}
    			
    			break;
    		}
    
    cout << "NO" << endl;
    
    return 0;
}
