class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>ans;
        int size = nums.size();
        int index=0;
        for(int i = 0; i<size; i++){
            index = abs(nums[i])-1;
            if(nums[index]<0)
                ans.push_back(index+1);
            nums[index] = -nums[index];
        }
        return ans;
    }
};