class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)
            return s;
        
        string solution = "";
        int down_step = 2 * numRows - 3;
        int up_step = down_step;
        
        for(int k = 0; k < numRows; ++k) {
            bool down = true;
            for(int i = k; i < s.length();) {
                solution += s[i];
                if(down)
                    i += down_step + 1;
                else
                    i += up_step + 1;
                down = !down;
            }
            
            if(k == 0) {
                down_step -= 2;
                up_step = 1;
            } else {
                down_step -= 2;
                up_step += 2;
            }
                
            if(down_step <= 0)
                down_step = up_step = 2 * numRows - 3;
        }
        
        return solution;
    }
};
