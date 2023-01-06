class Solution {
    bool isAdditiveNumberRec(string num, int idx, long long prev1, long long prev2, int cnt) {
        if(idx > num.length()) {
            return false;
        }

        if(idx == num.length() && cnt > 2) {
            return true;
        } else if (idx == num.length() && cnt <= 2) {
            return false;
        }

        bool ret = false;

        if(prev1 == -1 && prev2 == -1) {
            for(int i = idx + 1; i < idx + 18; ++i) {
                if(num[idx] != '0' || (num[idx] == '0' && i == 1)) {
                    ret |= isAdditiveNumberRec(num, i, stoll(num.substr(0, i)), -1, cnt + 1);
                }
            }
        } else if(prev2 == -1) {
            for(int i = idx + 1; i < idx + 18; ++i) {
                if(num[idx] != '0' || (num[idx] == '0' && i - idx == 1)) {
                    ret |= isAdditiveNumberRec(num, i, stoll(num.substr(idx, i - idx)), prev1, cnt + 1);
                }
            }
        } else {
            for(int i = idx + 1; i < idx + 18; ++i) {
                long long nxt = stoll(num.substr(idx, i - idx));
                if((num[idx] != '0' || (num[idx] == '0' && i - idx == 1)) && prev1 + prev2 == nxt) {
                    ret |= isAdditiveNumberRec(num, i, nxt, prev1, cnt + 1);
                }
            }
        }

        return ret;
    }

public:
    bool isAdditiveNumber(string num) {
        return isAdditiveNumberRec(num, 0, -1, -1, 0);
    }
};
