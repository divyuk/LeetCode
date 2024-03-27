class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) {
            return 0;
        }
        
        int left = 0;
        int product = 1;
        int count = 0;
        
        for (int right = 0; right < nums.size(); right++) {
            product *= nums[right];
            
            while (product >= k) {
                product /= nums[left];
                left++;
            }
            
            // Every time we move the right pointer,
            // we add the size of the window to the count.
            count += right - left + 1;
        }
        
        return count;
    }
};
