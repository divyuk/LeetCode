class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin() , nums.end());
       if(nums.size()<4)
        return ans;
        for(int i =0 ; i<nums.size()-3; i++){
            if(i!=0 and nums[i]==nums[i-1])
                continue;
            for(int j = i+1 ; j<nums.size()-2 ; j++){
                if(j!=i+1 and nums[j]==nums[j-1])
                    continue;
                
                int l = j+1;
                int r = nums.size()-1;
                while(l<r){
                    long long sum = (long)nums[i]+nums[j]+nums[l]+nums[r];
                    if(sum==target){
                         vector<int>v;
                        v.push_back(nums[i]);
                        v.push_back(nums[j]);
                        v.push_back(nums[l]);
                        v.push_back(nums[r]);
                        ans.push_back(v);
                        l++;
                        r--;
                        while(l<r and  nums[l]==nums[l-1])
                            l++;
                         while(l<r and  nums[r]==nums[r+1])
                            r--;
                        
                    }
                    else if(sum>target)
                        r--;
                    else if(sum<target)
                        l++;
                }

            }
        }
        return ans;
    }
};