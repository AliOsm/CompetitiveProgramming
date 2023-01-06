class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int l = 0, r = 0, res = 0;

        while(r < arr.size()) {
            bool ok1 = false;
            bool ok2 = false;

            while(r < arr.size() - 1 && arr[r] < arr[r + 1]) {
                ok1 = true;
                ++r;
            }

            while(r < arr.size() - 1 && arr[r] > arr[r + 1]) {
                ok2 = true;
                ++r;
            }

            if(ok1 && ok2) {
                res = max(res, r - l + 1);
            } else if(!ok1 && !ok2) {
                ++r;
            }

            l = r;
        }

        return res;
    }
};
