class Solution {
public:
    int minimumRightShifts(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted_nums = nums;
        sort(sorted_nums.begin(), sorted_nums.end());

        for (int i = 0; i < n; ++i) {
            if (nums == sorted_nums) {
                return i;
            }
            rotate(nums.rbegin(), nums.rbegin() + 1, nums.rend());
        }

        return -1;
    }
};
