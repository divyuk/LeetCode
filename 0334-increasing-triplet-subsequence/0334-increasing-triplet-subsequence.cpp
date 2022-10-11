class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = 0;
        n = nums.size();
        int left = INT_MAX, mid = INT_MAX;
        for (int  i = 0; i < n; i++)
        {
            if(left>=nums[i])
                left = nums[i];
            else if(mid >nums[i])
                mid = nums[i];
            else if(nums[i]>left and nums[i]>mid)
                return true;
        }
        
        return false;
    }
};