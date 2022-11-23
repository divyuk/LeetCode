class Solution {
public:
    bool valid(vector<vector<char>>& board ,int i ,int j,char num){
        for(int k = 0 ; k< 9 ; k++){
            // row
            if(k!=i and k!=j and board[i][k] == num)
                return false;
            
            // col
            if(k!=j and k!=i and board[k][j]  == num)
                return false;
            
            // mini board
            if( (3*(i/3) + k/3) != i and (3*(j/3) + k%3) != j and board[3*(i/3) + k/3][3*(j/3) + k%3] == num)
                return false;
            
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0 ; i < 9 ; i++){
            for(int j = 0 ; j<9 ; j++){
                if(board[i][j] != '.'){
                    char num = board[i][j];
                    if(valid(board , i , j,num))
                        continue;
                    
                    else
                        return false;
                    
                }
            }
        }
        return true;
    }
};