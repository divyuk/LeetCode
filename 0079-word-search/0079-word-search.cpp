#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool dfs(vector<vector<char>>& board, string& word, int index, int i, int j) {
        // If we have checked all the characters of the word
        if (index == word.length()) {
            return true;
        }
        
        // Check if the current cell is out of bounds or doesn't match the character in the word
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[index]) {
            return false;
        }
        
        // Temporarily mark the current cell as visited
        char temp = board[i][j];
        board[i][j] = '*';
        
        // Check the neighboring cells
        bool found = dfs(board, word, index + 1, i + 1, j) ||
                     dfs(board, word, index + 1, i - 1, j) ||
                     dfs(board, word, index + 1, i, j + 1) ||
                     dfs(board, word, index + 1, i, j - 1);
        
        // Restore the original value of the current cell
        board[i][j] = temp;
        
        return found;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();
        
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(board[i][j] == word[0] && dfs(board, word, 0, i, j)) {
                    return true;
                }
            }
        }
        return false;
    }
};
