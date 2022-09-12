class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        unordered_set<int>u(nums.begin(),nums.end());
        int count =0;
        for(auto i : u)
            if(u.find(i-diff)!=u.end() and u.find(i-2*diff)!=u.end())
                count++;
        
        return count;
    }
};