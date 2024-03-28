class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> frequency;
        int left = 0, right = 0;
        int maxLen = 0;
        
        while (right < nums.size()) {
            frequency[nums[right]]++;
            
            while(frequency[nums[right]] > k){
                frequency[nums[left]]--;
                left++;
            }
            
            maxLen = max(maxLen, right - left + 1);
            right++;
        }
        
        return maxLen;
    }
};
