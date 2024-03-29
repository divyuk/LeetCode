class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if(original.size() != m*n) return {};
        vector<vector<int>> ans;
        int j =0; int k=0;
        for(int i = 0; i< m; i++){
            vector<int>temp;
            for( j =0 ;j<n;j++){
                temp.push_back(original[k++]);
            }

            ans.push_back(temp);
        }
        
        return ans;
    }
};