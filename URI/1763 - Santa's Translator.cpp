#include <iostream>
#include <map>
#include <cstdlib>

using namespace std;

map<string, string> m;

int main() {
    m["brasil"] = "Feliz Natal!";
    m["alemanha"] = "Frohliche Weihnachten!";
    m["austria"] = "Frohe Weihnacht!";
    m["coreia"] = "Chuk Sung Tan!";
    m["espanha"] = "Feliz Navidad!";
    m["grecia"] = "Kala Christougena!";
    m["estados-unidos"] = "Merry Christmas!";
    m["inglaterra"] = "Merry Christmas!";
    m["australia"] = "Merry Christmas!";
    m["portugal"] = "Feliz Natal!";
    m["suecia"] = "God Jul!";
    m["turquia"] = "Mutlu Noeller";
    m["argentina"] = "Feliz Navidad!";
    m["chile"] = "Feliz Navidad!";
    m["mexico"] = "Feliz Navidad!";
    m["antardida"] = "Merry Christmas!";
    m["canada"] = "Merry Christmas!";
    m["irlanda"] = "Nollaig Shona Dhuit!";
    m["belgica"] = "Zalig Kerstfeest!";
    m["italia"] = "Buon Natale!";
    m["libia"] = "Buon Natale!";
    m["siria"] = "Milad Mubarak!";
    m["marrocos"] = "Milad Mubarak!";
    m["japao"] = "Merii Kurisumasu!";
    
    string s;
    while(cin >> s) {
        for(int i = 0; i < s.length(); i++) s[i] = tolower(s[i]);
        if(m[s] != "") cout << m[s] << endl;
        else cout << "--- NOT FOUND ---" << endl;
    }
    
    return 0;
}
