class Solution {
public:
        int subsetXORSum(vector<int>& nums) {
        return allSubs(0, nums, 0);
    }
    
    int allSubs(int cur, vector<int>& nums, int xoR) {
        if (cur == nums.size()) {
            return xoR;
        }
        // Include
        int include = allSubs(cur + 1, nums, nums[cur] ^ xoR);
        // Exclude
        int exclude = allSubs(cur + 1, nums, xoR);
        return include + exclude;
    }
};