class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        typedef pair<int,int>SolRow;
        priority_queue<SolRow, vector<SolRow>, greater<SolRow>>pq;
        
        for(int i =0; i<mat.size() ; i++){
            int sum = accumulate(mat[i].begin() , mat[i].end() ,0);
            pq.push({sum,i});
        }
        vector<int>ans;
        while(k-- ){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};