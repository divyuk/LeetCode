class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int>uset;
        unordered_set<int>::iterator it;
        int length=0,longest=0;
        
        for(int i : nums) uset.insert(i);
        
        for(unordered_set<int>::iterator it=uset.begin(); it!=uset.end();it++)         {
            int currentNumber = *it;
            
            if(uset.find(currentNumber-1) !=uset.end() ) continue; // this is not the starting of the chain
            length =1;
            while(uset.find(currentNumber+1) !=uset.end()){
                length++;
                currentNumber++;
            }
            longest = max(length,longest);
        }
        
    return longest;
    }
};