class Solution {
public:
    int longestSubstring(string s, int k) {
        int maxLength = 0;
        for (int numUnique = 1; numUnique <= 26; ++numUnique) { // There are at most 26 unique characters
            int left = 0, right = 0, unique = 0, atLeastK = 0;
            unordered_map<char, int> count;
            while (right < s.length()) {
                if (count[s[right]] == 0) ++unique; // Increment unique character count
                ++count[s[right]]; // Increment character count
                if (count[s[right]] == k) ++atLeastK; // Increment character count that appears at least k times
                ++right;
                
                // Adjust the window
                while (unique > numUnique) {
                    if (count[s[left]] == k) --atLeastK;
                    --count[s[left]];
                    if (count[s[left]] == 0) --unique;
                    ++left;
                }
                
                // Check if the current window satisfies the condition
                if (unique == numUnique && unique == atLeastK) {
                    maxLength = max(maxLength, right - left);
                }
            }
        }
        return maxLength;
    }
};