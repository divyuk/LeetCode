class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        multimap<int,int>ans;
        int r=0;
        for(auto i : mat){
            int cnt =0;
            for(int j =0 ;j<i.size() ;j++)
                if(i[j]==1) cnt++;
           ans.insert({cnt, r});
           r++;
        }        
        vector<int>res;
        int i =0;
        for(auto it : ans){
            if(k==0) break;
            res.push_back(it.second);
            k--;
        }
        
        return res;
    }
};