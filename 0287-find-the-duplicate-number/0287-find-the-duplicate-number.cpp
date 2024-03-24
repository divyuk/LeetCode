class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow =0,fast =0;
        do{
            slow=nums[slow];
            fast = nums[nums[fast]];
        }while(slow!=fast);
        int restart=0;
        while(restart!=slow){
            slow=nums[slow];
            restart=nums[restart];
        }
        return slow;
    }
};