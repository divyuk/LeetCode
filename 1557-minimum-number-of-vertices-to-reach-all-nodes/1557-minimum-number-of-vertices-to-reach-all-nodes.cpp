class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int>degree(n);
        for(auto x : edges){
            // degree[x[0]]--;
            degree[x[1]]++;
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(degree[i]==0) ans.push_back(i);
        }
        return ans;
    }
};