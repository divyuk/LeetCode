class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        vector<int> ans;
        unordered_map<int,int>umap;
        int n = changed.size();
        if(n%2 != 0) return {};
        
        sort(changed.begin() , changed.end());
        for(auto& num : changed ) umap[num]++;
        
        for(auto& num : changed  ){
            int douleNum = num*2;
            if(umap[num] == 0) continue;
            if(umap.find(douleNum) == umap.end() or umap[douleNum] == 0) return {};
            
            ans.push_back(num);
            
            umap[douleNum]--;
            umap[num]--;
 
        }
        
        return ans;
    }
};