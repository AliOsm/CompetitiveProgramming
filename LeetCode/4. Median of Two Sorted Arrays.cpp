class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size())
            swap(nums1, nums2);
        
        int l = 0, r = nums1.size(), mid1, mid2;
        while(l <= r) {
            mid1 = (l + r) / 2;
            mid2 = (nums1.size() + nums2.size() + 1) / 2 - mid1;
            
            int nums1_left, nums1_right, nums2_left, nums2_right;
            
            if(mid1 - 1 >= 0)
                nums1_left = nums1[mid1 - 1];
            else
                nums1_left = -2e9;
            
            if(mid1 < nums1.size())
                nums1_right = nums1[mid1];
            else
                nums1_right = 2e9;
            
            if(mid2 - 1 >= 0)
                nums2_left = nums2[mid2 - 1];
            else
                nums2_left = -2e9;
            
            if(mid2 < nums2.size())
                nums2_right = nums2[mid2];
            else
                nums2_right = 2e9;
            
            if(nums1_left <= nums2_right && nums2_left <= nums1_right) {
                if((nums1.size() + nums2.size()) & 1)
                    return max(nums1_left, nums2_left);
                return (max(nums1_left, nums2_left) + min(nums1_right, nums2_right)) / 2.0;
            } else if(nums2_left > nums1_right)
                l = mid1 + 1;
            else
                r = mid1 - 1;
        }
        
        return -1;
    }
};
