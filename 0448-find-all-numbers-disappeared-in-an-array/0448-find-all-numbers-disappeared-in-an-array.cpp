class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int>ans;
        // mark the existing numbers in the array
        for(int n : nums){
            int i = abs(n)-1;
            nums[i] = -1 * abs(nums[i]);
        }
        for(int i = 0 ; i< nums.size() ; i++){
            if(nums[i] > 0)
                ans.push_back(i+1);
        }
        return ans;
    }
};