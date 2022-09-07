class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        int n = nums.size();
        vector<int> ans;
        for(int i = 0;i<nums.size() ; i++){
            int in = index[i];
            ans.insert(ans.begin()+in , nums[i]); 
        }
        return ans;
    }
};