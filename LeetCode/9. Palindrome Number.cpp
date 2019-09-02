class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        
        long long reverse = 0, tmp = x;
        while(tmp != 0) {
            reverse = reverse * 10 + tmp % 10;
            tmp /= 10;
        }
        
        return x == reverse;
    }
};
