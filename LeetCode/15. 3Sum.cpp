class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<vector<int> > result;
        
        for (int i = 0, l, r; i < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            l = i + 1, r = nums.size() - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                
                if (sum > 0)
                    --r;
                else if (sum < 0)
                    ++l;
                else {
                    vector<int> tmp;
                    tmp.push_back(nums[i]);
                    tmp.push_back(nums[l]);
                    tmp.push_back(nums[r]);
                    result.push_back(tmp);
                    
                    while (l + 1 < nums.size() && nums[l] == nums[l + 1])
                        ++l;
                    ++l;
                    
                    while (r - 1 > i && nums[r] == nums[r - 1])
                        --r;
                    --r;
                }
            }
        }

        return result;
    }
};
