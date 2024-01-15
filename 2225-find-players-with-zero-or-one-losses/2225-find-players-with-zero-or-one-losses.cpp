class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int>umap;
        for(auto it : matches){
            int l = it[1];
            umap[l]++;
        }
        // for(auto it : umap){
        //     cout<< it.first <<" "<< it.second<<"\n";
        // }
        vector<vector<int>>ans(2);
        
        for(auto it : umap){
            if(it.second == 1)
                ans[1].push_back(it.first);
        }
        
        set<int>s;
        for(auto it : matches){
            if(umap.find(it[0])== umap.end())
                s.insert(it[0]);
        }
        for(int i : s){
            ans[0].push_back(i);
        }
        return ans;
    }
};