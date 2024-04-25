#define ll long long

class Solution {
private:
    long long f(vector<int>& nums, int idx, bool flag, vector<vector<ll>>& dp) {
        if (idx >= nums.size()) return 0;
        
        if (dp[idx][flag] != -1) return dp[idx][flag];
        
        ll notTake = f(nums, idx + 1, flag, dp);
        
        ll val = nums[idx];
        if (!flag) val = -val; // Simplified condition
        ll take = f(nums, idx + 1, !flag, dp) + val;
        
        return dp[idx][flag] = max(take, notTake);
    }
    
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();

        // Initialize variables to store the previous row values
        long long even = 0; // Maximum alternating sum ending at an even index
        long long odd = 0;  // Maximum alternating sum ending at an odd index

        for(int i = 0; i < n; i++) {
            // Calculate the maximum alternating sum ending at the current index
            long long new_even = max(odd - nums[i], even);
            long long new_odd = max(even + nums[i], odd);

            // Update even and odd for the next iteration
            even = new_even;
            odd = new_odd;
        }

        // The maximum alternating sum will be the maximum of the last even and odd values
        return max(even, odd);
    }
};
