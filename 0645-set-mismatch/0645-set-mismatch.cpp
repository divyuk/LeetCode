class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
    unordered_set<int> numSet;
    int n = nums.size();

    int duplicate = -1, missing = -1;
    
    // Find the duplicate number
    for (int i = 0; i < n; i++) {
        if (numSet.find(nums[i]) != numSet.end()) {
            duplicate = nums[i];
        } else {
            numSet.insert(nums[i]);
        }
    }
    
    // Find the missing number
    for (int i = 1; i <= n; i++) {
        if (numSet.find(i) == numSet.end()) {
            missing = i;
            break;
        }
    }

    
    return {duplicate, missing };
  
    }
};