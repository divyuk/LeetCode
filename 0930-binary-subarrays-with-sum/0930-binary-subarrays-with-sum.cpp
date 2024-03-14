class Solution {
public:
    
    int countSubarray(vector<int>& nums, int x){
        if(x<0) return 0;
        int res=0;
        int n = nums.size();
        int l=0,curr=0, r=0;
        while(r<n){
            curr+=nums[r];
            while(curr>x){
                curr-=nums[l];
                l++;
            }
            res+=(r-l+1);
            r++;
        }
        return res;
    }
    
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        return countSubarray(nums,goal) - countSubarray(nums,goal-1);
    }
};