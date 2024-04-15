class Solution {
public:
    int maxSubarrayLength(vector<int>& nums) {
        int n = nums.size();
        stack<int>stk;
        for(int i = 0; i< n; i++){
            if(stk.empty() || nums[stk.top()] < nums[i]  ) stk.push(i);
        }
        int maxLen = 0;
        for(int i = n-1; i>=0; i--){
            while(!stk.empty() and nums[stk.top()] > nums[i]){
                maxLen = max(maxLen, (i - stk.top() )+1);
                stk.pop();
            }
        }
        return maxLen;
    }
};