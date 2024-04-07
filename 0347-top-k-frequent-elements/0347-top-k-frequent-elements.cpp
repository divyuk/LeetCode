class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ans;
        unordered_map<int,int>m;
        for(int i : nums)
            m[i]++;
        
        vector<vector<int>>temp(nums.size()+1);
        for(auto it = m.begin() ; it!= m.end() ; it++)
            temp[it->second].push_back(it->first);
        
        for(int i = nums.size() ; i>=0;i--){
            if(ans.size()>=k)
                break;
            if(!temp[i].empty())
                ans.insert(ans.end() , temp[i].begin() , temp[i].end());
        }
        return ans;
    }
};