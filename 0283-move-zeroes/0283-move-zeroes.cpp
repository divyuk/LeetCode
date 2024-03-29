class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // Idea is to have the left pointer point to zero if there its.
        int left = 0;
        for(int r = 0;r<nums.size() ; r++){
            if(nums[r]){
                swap(nums[left] , nums[r]);
                left++;
            }
        }
    }
};