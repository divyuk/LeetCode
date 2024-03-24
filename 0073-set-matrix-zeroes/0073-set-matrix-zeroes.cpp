class Solution {
public:
    
    void markRow(int row, int c , vector<vector<int>>& matrix){
        for(int i = 0;i<c;i++) 
            if(matrix[row][i]!=0)
                matrix[row][i] = -999;

    }
    
    void markCol(int col, int r , vector<vector<int>>& matrix){
        for(int i = 0;i<r;i++)
            if(matrix[i][col]!=0)
                matrix[i][col] = -999;

    }
    
    void setZeroes(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        
        for(int i = 0; i<r;i++){
            for(int j =0 ; j<c;j++){
                if(matrix[i][j] == 0){
                    markRow(i,c,matrix);
                    markCol(j,r,matrix);
                }
            }
        }
        
        for(int i = 0; i<r;i++){
            for(int j =0 ; j<c;j++){
                if(matrix[i][j] == -999) matrix[i][j] = 0;
            }
        }
        
        
    }
};