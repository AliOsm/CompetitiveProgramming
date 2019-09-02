class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        
        int a, b;
        for(int i = 0, need; i < nums.size(); ++i) {
            need = target - nums[i];
            if(m.count(need) != 0) {
                a = i, b = m[need];
                break;
            }
            m[nums[i]] = i;
        }
        
        vector<int> solution;
        solution.push_back(a);
        solution.push_back(b);
        return solution;
    }
};
