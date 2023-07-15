class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        vector<int>bucket(101,0);
        
        for(auto i : nums)
            bucket[i]++;
        
        // for(int i = 0;i<9;i++)
        //     cout<<bucket[i]<<" ";
        // Prefix sum
        for (int i = 1; i < bucket.size(); i++)
            bucket[i] +=bucket[i-1];
        
        for(int i = 0;i<9;i++)
            cout<<bucket[i]<<" ";
        
        vector<int>ans(n,0);
        for(int i = 0;i<n;i++){
            if(nums[i]==0)
                ans[i]=0;
            else
                ans[i] = bucket[nums[i]-1];
             
            
        }

        return ans;
    }
};