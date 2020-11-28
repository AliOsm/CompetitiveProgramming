class Solution {
public:
    int romanToInt(string s) {
        map<string, int> charToCount;

        charToCount["I"] = 1;
        charToCount["V"] = 5;
        charToCount["X"] = 10;
        charToCount["L"] = 50;
        charToCount["C"] = 100;
        charToCount["D"] = 500;
        charToCount["M"] = 1000;

        charToCount["IV"] = 4;
        charToCount["IX"] = 9;
        charToCount["XL"] = 40;
        charToCount["XC"] = 90;
        charToCount["CD"] = 400;
        charToCount["CM"] = 900;

        int num = 0;

        for (int i = 0; i < s.length(); ++i) {
            string currentNum = "";
            currentNum += s[i];

            if (i + 1 < s.length() && charToCount.count(currentNum + s[i + 1]))
                num += charToCount[currentNum + s[i + 1]], ++i;
            else
                num += charToCount[currentNum];
        }

        return num;
    }
};
