class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int>uset;
        int length = 0,longest=0;
        for(auto it : nums)
            uset.insert(it);
        
        for(auto it = uset.begin() ; it!=uset.end() ; it++){
            
            int currentNum = *it;
            if(uset.find(currentNum-1) != uset.end()) continue; // this maybe the starting point of the chain
            length = 1;
            while(uset.find(currentNum+1) != uset.end() ){
                length++;
                currentNum++;
            }
            longest = max(longest , length);
        }
        
        return longest;
    }
};