class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int>ans,d(n);
        for(auto &i : edges )
            d[i[1]]++;
        
        for(int i = 0 ; i< n;i++){
            if(d[i] == 0)
                ans.push_back(i);
        }
        return ans;
    }
};