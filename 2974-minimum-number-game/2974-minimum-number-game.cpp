class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int n = nums.size(),i=0;
        vector<int>ans(n,0);
        while(i<n){
            ans[i] = nums[i+1];
            ans[i+1] = nums[i];
            i+=2;
        }
        return ans;
    }
};