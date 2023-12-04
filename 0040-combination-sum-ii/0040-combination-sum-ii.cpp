class Solution {
public:
    vector<vector<int>>result;
    void create(int start, vector<int>& nums, vector<int>& container, int total, int target) {
        if (total == target) {
            result.push_back(container);
            return;
        }

        for (int i = start; i < nums.size(); i++) {
            // Skip duplicates
            if (i > start && nums[i] == nums[i - 1]) continue;
            if(total > target) break;
            // Include the current element in the combination
            container.push_back(nums[i]);
            create(i + 1, nums, container, total + nums[i], target);
            // Backtrack
            container.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        vector<int>container;
        sort(nums.begin() , nums.end());
        create(0,nums,container,0, target);
        return result;
    }
};