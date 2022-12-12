class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int>u;
        int c =0;
        for(int i : nums){
            c+=u[i]++;
        }
        return c;
    }
};