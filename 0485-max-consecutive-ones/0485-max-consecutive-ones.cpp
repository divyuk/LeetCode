class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int i = 0, n = nums.size() , c=0, ans=0;
        while(i<n){
            c = nums[i] == 1 ? ++c : 0;
            ans = max(ans,c);
            i++;
        }
        return ans;
    }
};