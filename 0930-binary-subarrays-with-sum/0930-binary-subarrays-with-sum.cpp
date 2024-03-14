class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int count = 0;
        int sum = 0;
        unordered_map<int, int> prefixSums;
        
        for (int num : nums) {
            prefixSums[sum]++;
            sum += num;
            count += prefixSums[sum - goal];
        }
        
        return count;
    }
};
