#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct stu {
	string name;
	int p, a;
};

vector<stu> arr;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
    	arr.clear();
    	
    	int n;
    	cin >> n;
    	
    	while(n--) {
    		string s;
    		cin >> s;
    		stu nstu;
    		nstu.name = s;
    		nstu.p = 0;
    		nstu.a = 0;
    		arr.push_back(nstu);
    	}

    	n = arr.size();

    	for(int i = 0; n--; i++) {
    		string s;
    		cin >> s;
    		int p = 0, a = 0;
    		for(int j = 0, len = s.length(); j < len; j++)
    			if(s[j] == 'A') arr[i].a++;
    			else if(s[j] == 'P') arr[i].p++;
    	}

    	n = arr.size();

    	bool f = false;
    	for(int i = 0; n--; i++)
    		if(arr[i].p < (arr[i].a + arr[i].p) / 100.0 * 75) {
    			if(f) cout << ' ';
    			cout << arr[i].name;
    			f = true;
    		}
    	cout << endl;
    }
    
    return 0;
}
