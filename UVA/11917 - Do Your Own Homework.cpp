#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    for(int i = 0; t--; i++) {
        map<string, int> arr;
        int subjects;
        cin >> subjects;

        for(int j = 0; j < subjects; j++) {
            string subject;
            int days;
            cin >> subject >> days;

            arr[subject] = days;
        }

        int days;
        cin >> days;

        string subject;
        cin >> subject;

        cout << "Case " << i + 1 << ": ";

        if(arr[subject] && arr[subject] <= days)
            cout << "Yesss";
        else if(arr[subject] && arr[subject] <= days + 5)
            cout << "Late";
        else
            cout << "Do your own homework!";

        cout << endl;
    }

    return 0;
}
