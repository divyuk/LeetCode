class Solution {
public:
    
    void setZeroes(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        vector<int>rowArray(r,0);
        vector<int>colArray(c,0);
        
        for(int i = 0; i<r;i++){
            for(int j =0 ; j<c;j++){
                if(matrix[i][j] == 0){
                    rowArray[i] = 1;
                    colArray[j] = 1;
                }
            }
        }
        
      for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (rowArray[i] || colArray[j]) {
                    matrix[i][j] = 0;
                }
            }
        }


    }
};