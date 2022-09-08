class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int>ans(rowIndex+1);
        long temp = 1;
        ans[0] = 1;
        ans[rowIndex]  = 1;
        int up = rowIndex;
        int down  = 1;
        for(int i = 1 ; i<rowIndex ; i++){
            temp = temp * up / down;
            up--;
            down++;
            ans[i] = temp; 
        } 
        return ans;
    }
};