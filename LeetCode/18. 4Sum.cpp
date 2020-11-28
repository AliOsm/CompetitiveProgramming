class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        vector<vector<int> > result;
        
        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            for (int j = i + 1, l, r; j < nums.size(); ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                l = j + 1, r = nums.size() - 1;
                while (l < r) {
                    int sum = nums[i] + nums[j] + nums[l] + nums[r];

                    if (sum > target)
                        --r;
                    else if (sum < target)
                        ++l;
                    else {
                        vector<int> tmp;
                        tmp.push_back(nums[i]);
                        tmp.push_back(nums[j]);
                        tmp.push_back(nums[l]);
                        tmp.push_back(nums[r]);
                        result.push_back(tmp);

                        while (l + 1 < nums.size() && nums[l] == nums[l + 1])
                            ++l;
                        ++l;

                        while (r - 1 > j && nums[r] == nums[r - 1])
                            --r;
                        --r;
                    }
                }
            }
        }

        return result;
    }
};
