class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        int n= nums.size();
        
        for(int i=0; i<n; i++){
            if (mp.find(target-nums[i]) != mp.end()) //if(mp.count(target-nums[i]))
                return {mp[target-nums[i]],i};
            
            mp[nums[i]]=i;
        }
        for(auto it:mp)
            cout<<it.first<<" "<<it.second<<"\n";
        return {};

    }
};