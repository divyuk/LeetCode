class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int>check;
        int ans = -1;
        for(int i : nums){
            if(i<0){
                if(check.find(abs(i)) != check.end()){
                    ans = max(ans, abs(i));
                }
            }
            else{
                if(check.find(-i) != check.end()){
                    ans = max(ans, i);
                 }
            }
            check.insert(i);
        }
        return ans;
    }
};