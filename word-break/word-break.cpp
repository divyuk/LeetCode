class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[n] = true; // Base case: empty string can be segmented
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        for (int i = n - 1; i >= 0; i--) {
            for (string& word : wordDict) {
                if (i + word.size() <= n && dict.find(s.substr(i, word.size())) != dict.end()) {
                    dp[i] = dp[i] || dp[i + word.size()];
                }
            }
        }
        return dp[0];
    }
};