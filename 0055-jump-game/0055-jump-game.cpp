class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int goal =0;
        for(int i  = n-1 ; i>=0 ; i--){
            if(nums[i]+i>=goal)
                goal = i;
            }
        // return true ? !goal : false;
        
        return !goal;
    }
};