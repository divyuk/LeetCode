class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
//         unordered_map<int , int>u;
 
//         for(int i = 0 ; i<nums.size() ; i++){
//             u[nums[i]]++;
//         }
//         for(auto i : nums){
//             if(u[i] >= 2)
//                 return true;
//         }
//         return false;
        
        return nums.size() > set<int>(nums.begin(), nums.end()).size(); 
    }
};