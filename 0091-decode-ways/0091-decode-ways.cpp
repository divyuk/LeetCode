class Solution {
public:
    int numDecodings(std::string s) {
        int n = s.size();
        if (n == 0 || s[0] == '0') {
            return 0;
        }

        // dp[i] represents the number of ways to decode the substring s[0:i].
        std::vector<int> dp(n + 1, 0);
        dp[0] = 1; // Empty string is considered as one way (base case).

        for (int i = 1; i <= n; ++i) {
            // Check for single-digit decoding.
            if (s[i - 1] != '0') {
                dp[i] += dp[i - 1];
            }

            // Check for two-digit decoding if possible.
            if (i > 1 && isValidTwoDigit(s.substr(i - 2, 2))) {
                dp[i] += dp[i - 2];
            }
        }

        return dp[n];
    }

private:
    bool isValidTwoDigit(const std::string& twoDigits) {
        int value = std::stoi(twoDigits);
        return value >= 10 && value <= 26;
    }
};
