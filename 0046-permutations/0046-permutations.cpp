class Solution {
public:
    vector<vector<int>>ans;
    
    void fun(int index , vector<int>nums){
        if(index==nums.size()){
            ans.push_back(nums);
            return;
        }
        
        for(int i = index; i<nums.size() ; i++){
            swap(nums[index] , nums[i]);
            fun(index+1, nums);
            swap(nums[index] , nums[i]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        fun(0,nums);
        return ans;
    }
};