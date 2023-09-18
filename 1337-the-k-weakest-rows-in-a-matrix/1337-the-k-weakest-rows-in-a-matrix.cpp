class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<vector<int>>temp(mat.size() , vector<int>(2,0));
        for(int i =0; i<mat.size() ; i++){
            int sum = accumulate(mat[i].begin() , mat[i].end() ,0);
            temp[i][0] = sum;
            temp[i][1] = i;
        }
        sort(temp.begin() , temp.end());
        vector<int>ans;
        for(int i =0;i<k;i++)
            ans.push_back(temp[i][1]);
        return ans;
    }
};