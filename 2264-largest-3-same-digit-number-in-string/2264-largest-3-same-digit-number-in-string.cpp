class Solution {
public:
    string largestGoodInteger(string num) {
        string ans = "";
        for (int i = 0; i < num.size() - 2; i++) {
            string s = num.substr(i, 3);
            if (s[0] == s[1] && s[1] == s[2] && s > ans) {
                ans = s;
            }
        }
        return ans;
    }
};