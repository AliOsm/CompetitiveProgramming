class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int best = 1e9;

        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                int sum = nums[i] + nums[j];
                int itmp = nums[i];
                int jtmp = nums[j];

                if (i + 1 == j) {
                    if (j + 1 < nums.size())
                        nums[i] = nums[j] = nums[j + 1];
                    else
                        nums[i] = nums[j] = nums[i - 1];
                } else {
                    if (i > 0)
                        nums[i] = nums[i - 1];
                    else
                        nums[i] = nums[i + 1];

                    nums[j] = nums[j - 1];
                }

                int l = 0 , r = nums.size() - 1;
                while (l < r) {
                    int mid = (l + r) / 2;

                    if (abs(target - best) > abs(target - (sum + nums[mid])))
                        best = sum + nums[mid];

                    if (sum + nums[mid] == target)
                        return target;

                    else if (sum + nums[mid] < target)
                        l = mid + 1;
                    else
                        r = mid - 1;
                }

                nums[i] = itmp;
                nums[j] = jtmp;
            }
        }

        return best;
    }
};
