class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int globalMax = nums[0], globalMin = nums[0];
        int currMax = 0, currMin =0;
        int total =0;
        for(int n : nums){
            currMax = max(currMax+n,n );
            currMin = min(currMin+ n, n);
            total+=n;
            globalMax = max(globalMax, currMax);
            globalMin = min(globalMin, currMin);
        }
        
        return (globalMax<=0)? globalMax : max(globalMax, total-globalMin); 
    }
};