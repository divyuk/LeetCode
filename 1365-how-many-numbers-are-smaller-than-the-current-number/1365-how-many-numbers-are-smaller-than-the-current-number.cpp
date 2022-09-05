class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int>ans;
        int n = nums.size();
        ans.reserve(n);
        for(int i = 0;i<n;i++ ){
            int count=0;
            for(int j = 0 ;j<n;j++){
                if(i!=j and nums[i]>nums[j])
                    count++;
            }
            ans.push_back(count);
        }
        return ans;
    }
};