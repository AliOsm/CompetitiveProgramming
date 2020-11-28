class Solution {
public:
    string intToRoman(int num) {
        string ones = getPlace(num % 10, "I", "V", "X");
        string tens = getPlace(num / 10 % 10, "X", "L", "C");
        string hundreds = getPlace(num / 100 % 10, "C", "D", "M");
        string thousands = "";
        num = num / 1000;
        while (num--)
            thousands += "M";
        return thousands + hundreds + tens + ones;
    }

private:
    string getPlace(int num, string one, string five, string ten) {
        if (num == 9)
            return one + ten;

        if (num == 4)
            return one + five;
        
        string tens = "";

        if (num > 4) {
            tens = five;
            num -= 5;
        }

        while (num--)
            tens += one;

        return tens;
    }
};
