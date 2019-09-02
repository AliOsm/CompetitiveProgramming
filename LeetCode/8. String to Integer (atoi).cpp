class Solution {
public:
    int myAtoi(string str) {
        char sign = '+';
        int index = -1;
        for(int i = 0; i < str.length(); ++i) {
            if(str[i] != '-' && str[i] != '+' && str[i] != ' ' && !isdigit(str[i]))
                return 0;
            if(str[i] == '-')
                sign = '-';
            if(str[i] == '-' && i + 1 < str.length() && !isdigit(str[i + 1]))
                return 0;
            if(str[i] == '+')
                sign = '+';
            if(str[i] == '+' && i + 1 < str.length() && !isdigit(str[i + 1]))
                return 0;
            if(isdigit(str[i])) {
                index = i;
                break;
            }
        }
        
        if(index == -1)
            return 0;
        
        int solution = 0;
        for(int i = index; isdigit(str[i]) && i < str.length(); ++i) {
            if(solution > INT_MAX / 10 || (solution == INT_MAX / 10 && str[i] - '0' > 7))
                return INT_MAX;
            if(solution < INT_MIN / 10 || (solution == INT_MIN / 10 && str[i] - '0' > 8))
                return INT_MIN;
            
            if(sign == '-')
                solution = solution * 10 + -(str[i] - '0');
            else
                solution = solution * 10 + (str[i] - '0');
        }
        
        return solution;
    }
};
