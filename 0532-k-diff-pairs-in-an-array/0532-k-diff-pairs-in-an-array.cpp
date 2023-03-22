class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        
        int c=0;
        sort(nums.begin() , nums.end());
        unordered_set<int>s;
        unordered_set<int>r;
        for(int i:nums){
            if(s.find(i) != s.end()) r.insert(i);
            s.insert(i);
        }

        if(k==0) return r.size();

        for(int i :s)
            if(s.find(k+i) != s.end() ) c++;

        return c;
    }
};