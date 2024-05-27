class Solution {
public:
    int specialArray(vector<int>& nums) {
        // Sort the array to facilitate binary search
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        // Perform binary search to find the special value x
        for (int x = 0; x <= n; ++x) {
            // Find the number of elements >= x using lower_bound
            int count = n - (lower_bound(nums.begin(), nums.end(), x) - nums.begin());
            if (count == x) {
                return x;
            }
        }
        
        return -1;
    }
};