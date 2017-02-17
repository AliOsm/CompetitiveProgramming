#include <iostream>
#include <vector>

using namespace std;

int main(){
    int ac = 0, oc = 0;
    
    int s, t;
    cin >> s >> t;
    
    int a, b;
    cin >> a >> b;
    
    int m, n;
    cin >> m >> n;
    
    vector<int> apple(m);
    for(int apple_i = 0;apple_i < m;apple_i++){
        cin >> apple[apple_i];
        if(a + apple[apple_i] >= s && a + apple[apple_i] <= t && apple[apple_i] > 0)
            ac++;
    }
    cout << ac << endl;
    
    vector<int> orange(n);
    for(int orange_i = 0;orange_i < n;orange_i++){
        cin >> orange[orange_i];
        if(b + orange[orange_i] >= s && b + orange[orange_i] <= t && orange[orange_i] < 0)
            oc++;
    }
    cout << oc << endl;
    
    return 0;
}
