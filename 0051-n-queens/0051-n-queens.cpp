class Solution {
public:
    vector<vector<string>> ans;
    void solve(int n , int row , int leftDiagonal[] , int rightDiagonal[] , int column[] , vector<string>&board){
        if(row == n){
            ans.push_back(board);
            return;
        }
        for(int col = 0 ; col< n ; col++){
            if(board[row][col] == '.' and leftDiagonal[row-col+n-1] == 0  
            and rightDiagonal[row+col] == 0  and column[col] == 0 ){
                board[row][col] = 'Q';
                leftDiagonal[row-col+n-1] = 1;
                rightDiagonal[row+col] = 1;
                column[col] = 1;
                cout<<col   <<" ";
                solve(n , row+1 , leftDiagonal , rightDiagonal , column , board);
                board[row][col] = '.';
                leftDiagonal[row-col+n-1] = 0;
                rightDiagonal[row+col] = 0;
                column[col] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board;
        int leftDiagonal[2*n-1];
        memset(leftDiagonal , 0 , sizeof(leftDiagonal));
        int rightDiagonal[2*n-1];
        memset(rightDiagonal , 0 , sizeof(rightDiagonal));
        int column[n];
        memset(column , 0 , sizeof(column));
        
        for(int i = 0 ; i<n; i++){
            string temp;
            for(int j = 0 ; j< n;  j++){
                temp.push_back('.');
            }
            board.push_back(temp);
        }
        solve(n , 0, leftDiagonal , rightDiagonal , column , board);
        for(int i = 0 ; i<n; i++){
            for(int j = 0 ; j< n;  j++){
                cout<<board[i][j]<<" ";
            }
            cout<<"\n";
        }
       
        return ans;
    }
};