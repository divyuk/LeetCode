class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int,int>umap;
        for(int i : nums) umap[i]++;
        
        vector<int>ans(2,0);
        
        int idx=0;
        for(auto it : umap){
            if(it.second==1) ans[idx++] = it.first;
        }
        
        return ans;
    }
};