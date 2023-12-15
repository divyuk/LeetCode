class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string,int>umap;
        int n = paths.size();
        for(int i = 0 ; i< n ;i++){
            string go = paths[i][0];
            string dest = paths[i][1];
            umap[go]--;
            umap[dest]++;
        }
        for(auto it : umap)
            if(it.second>0) return it.first;
        
    return "";
    }
    
};