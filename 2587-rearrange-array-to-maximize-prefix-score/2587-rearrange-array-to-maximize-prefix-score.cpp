class Solution {
public:
    int maxScore(vector<int>& nums) {
        sort(nums.begin(),nums.end(),greater<int>());
        long long ans=0,p=0;
        for(int x : nums){
            p+=x;
            if(p>0)
                ans++;
        }
        return ans;
    }
};