class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left =0,right=0,n=s.size(),result=0;
        unordered_set<char>unique;
        while(right<n){
            while( unique.find(s[right]) !=unique.end() ){
                unique.erase(s[left]);
                left++;
            }
            unique.insert(s[right]);
            result = max(result , right-left+1);
            right++;
        }
        
        return result;
    }
};