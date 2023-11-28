class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int l =0;
        int n = nums.size();
        int c = 0,ans=0;
        while(l<n){  
            c = (nums[l] == 1) ? ++c : 0;
            l++;
            ans = max(ans , c);
        }
        return ans;
    }
};