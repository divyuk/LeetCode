class Solution {
    vector<int> bit;
    
    int query(int idx) {
        int sum = 0;
        while (idx > 0) {
            sum += bit[idx];
            idx -= idx & -idx;
        }
        return sum;
    }
    
    void update(int idx, int val) {
        while (idx < bit.size()) {
            bit[idx] += val;
            idx += idx & -idx;
        }
    }
    
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> sortedNums(nums);
        sort(sortedNums.begin(), sortedNums.end());
        
        // Initialize BIT with size equal to the maximum element in nums
        bit.resize(n + 1);
        
        vector<int> result(n);
        for (int i = n - 1; i >= 0; --i) {
            int idx = lower_bound(sortedNums.begin(), sortedNums.end(), nums[i]) - sortedNums.begin() + 1;
            result[i] = query(idx - 1);
            update(idx, 1);
        }
        
        return result;
    }
};
