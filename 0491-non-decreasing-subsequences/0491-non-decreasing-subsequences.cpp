class Solution {
private:
    vector<vector<int>>ans;
    void subsequencesGenerator(int idx , vector<int> &nums, vector<int>&curr){
        if(curr.size() >= 2) ans.push_back(curr);
        
        unordered_set<int>st;
        
        for(int i = idx; i<nums.size(); i++){
            if((curr.empty() or nums[i] >= curr.back()) and (st.find(nums[i]) == st.end())) {
                curr.push_back(nums[i]);
                subsequencesGenerator(i+1, nums, curr);
                curr.pop_back();
                st.insert(nums[i]);
            }
            
        }
        
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> curr;
        subsequencesGenerator(0,nums, curr);
        return ans;
    }
};