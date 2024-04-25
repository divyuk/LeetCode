class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        
        int prev2  = nums[0];
        int prev   = max(nums[1] , prev2);
        if(n == 2) return prev;
        int curr  = 0;
        for(int i = 2; i< n ; i++){
            curr = max(nums[i] + prev2 , prev );
            prev2 = prev;
            prev = curr;
        }
        return curr;
    }
};