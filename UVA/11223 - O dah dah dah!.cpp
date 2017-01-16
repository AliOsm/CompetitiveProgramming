#include <iostream>

using namespace std;

int main() {
    string A = ".-", B = "-...", C = "-.-.", D = "-..", E = ".", F = "..-.", G = "--.", H = "....", I = "..", J = ".---", K = "-.-", L = ".-..", M = "--", N = "-.", O = "---", P = ".--.", Q = "--.-", R = ".-.", S = "...", T = "-", U = "..-", V = "...-", W = ".--", X = "-..-", Y = "-.--", Z = "--..";
    string n0 = "-----", n1 = ".----", n2 = "..---", n3 = "...--", n4 = "....-", n5 = ".....", n6 = "-....", n7 = "--...", n8 = "---..", n9 = "----.";
    string dot = ".-.-.-", coma = "--..--", question_mark = "..--..", upper_coma = ".----.", bang_bang = "-.-.--", forward_slash = "-..-.", left_bow = "-.--.", right_bow = "-.--.-", anD = ".-...", colon = "---...", coma_colon = "-.-.-.", equal = "-...-", plus = ".-.-.", mines = "-....-", underscore = "..--.-", double_cotation = ".-..-.", at = ".--.-.";
    
    int t;
    cin >> t;
    
    cin.ignore();
    string s, ss;
    for(int c = 1; t--; c++) {
        getline(cin, s);
        
        cout << "Message #" << c << endl;
        
        for(int i = 0; i < s.size(); i++) {
            if (s[i]==' ') {
                if (s[i + 1]==' ')
                    cout << ' ';
                continue;
            }
            
            ss = "";
            while(s[i] != ' ' && i < s.size())
                ss += s[i++];
            i--;
            
            if(ss == A) cout << "A";
            else if(ss == B) cout << "B";
            else if(ss == C) cout << "C";
            else if(ss == D) cout << "D";
            else if(ss == E) cout << "E";
            else if(ss == F) cout << "F";
            else if(ss == G) cout << "G";
            else if(ss == H) cout << "H";
            else if(ss == I) cout << "I";
            else if(ss == J) cout << "J";
            else if(ss == K) cout << "K";
            else if(ss == L) cout << "L";
            else if(ss == M) cout << "M";
            else if(ss == N) cout << "N";
            else if(ss == O) cout << "O";
            else if(ss == P) cout << "P";
            else if(ss == Q) cout << "Q";
            else if(ss == R) cout << "R";
            else if(ss == S) cout << "S";
            else if(ss == T) cout << "T";
            else if(ss == U) cout << "U";
            else if(ss == V) cout << "V";
            else if(ss == W) cout << "W";
            else if(ss == X) cout << "X";
            else if(ss == Y) cout << "Y";
            else if(ss == Z) cout << "Z";
            else if(ss == n0) cout << "0";
            else if(ss == n1) cout << "1";
            else if(ss == n2) cout << "2";
            else if(ss == n3) cout << "3";
            else if(ss == n4) cout << "4";
            else if(ss == n5) cout << "5";
            else if(ss == n6) cout << "6";
            else if(ss == n7) cout << "7";
            else if(ss == n8) cout << "8";
            else if(ss == n9) cout << "9";
            else if(ss == n9) cout << "9";
            else if(ss == dot) cout << ".";
            else if(ss == coma) cout << ",";
            else if(ss == question_mark) cout << "?";
            else if(ss == upper_coma) cout << "\'";
            else if(ss == bang_bang) cout << "!";
            else if(ss == forward_slash) cout << "/";
            else if(ss == left_bow) cout << "(";
            else if(ss == right_bow) cout << ")";
            else if(ss == anD) cout << "&";
            else if(ss == colon) cout << ":";
            else if(ss == coma_colon) cout << ";";
            else if(ss == equal) cout << "=";
            else if(ss == plus) cout << "+";
            else if(ss == mines) cout << "-";
            else if(ss == underscore) cout << "_";
            else if(ss == double_cotation) cout << "\"";
            else if(ss == at) cout << "@";
        }
        
        cout << endl;
        if(t) cout << endl;
    }
    
    return 0;
}
