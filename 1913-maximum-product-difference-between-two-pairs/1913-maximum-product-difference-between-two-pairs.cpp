class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin() , nums.end());
        
        int a = nums[0];
        int b = nums[1];
        int c = nums[n-2];
        int d = nums[n-1];
        
        return ( (c*d) -  (a*b));
    }
};