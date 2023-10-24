class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>unique;
        int result = 0 , left = 0;
        int n = s.size();
        for (int right = 0; right < n; right++)
        {
            //! If duplicate remove 
            while(unique.find(s[right])!=unique.end()){
                unique.erase(s[left]);
                left+=1;
            }
            unique.insert(s[right   ]);
            result = max(result,right-left+1);
        }
        return result;
    }
};