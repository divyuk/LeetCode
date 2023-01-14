class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int x=0,y=0;
        int r =  mat.size();
        for(int i =0 ; i< r ; i++){
            x+=mat[i][i];
            y+=mat[i][r-i-1];
            
         }
        
        if(r%2==0)
            return x+y;
        return x+y-mat[r/2][r/2];
            
       }
    
};