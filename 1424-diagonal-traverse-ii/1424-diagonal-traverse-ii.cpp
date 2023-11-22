#include <vector>

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int> ans;
        unordered_map<int, vector<int>>mp;
        
        for(int row = nums.size()-1 ; row>=0 ; row--){
            for(int col = 0 ; col<nums[row].size() ;col++){
                int diagonal = row+col;
                mp[diagonal].push_back(nums[row][col]);
            }
        }
        
        int diagonal=0;
        while(mp.find(diagonal) != mp.end()){
            
            for(int &n : mp[diagonal]) ans.push_back(n);
            
            diagonal++;
        }

        return ans;
    }
};
