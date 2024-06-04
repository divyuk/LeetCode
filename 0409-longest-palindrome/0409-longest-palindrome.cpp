class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> frequencyMap;

        for (char c : s) frequencyMap[c]++;
        

        int res = 0;
        bool hasOddFrequency = false;
        for (auto& entry : frequencyMap) {
            int freq = entry.second;
            if (freq % 2 == 0)  res += freq;
             else {
                // If the frequency is odd, one occurrence of the
                // character will remain without a match
                res += freq - 1;
                hasOddFrequency = true;
            }
        }
        // If hasOddFrequency is true, we have at least one unmatched
        // character to make the center of an odd length palindrome.
        if (hasOddFrequency) return res + 1;

        return res;
    }
};