class Solution {
public:
    int numSteps(string s) {
        int n = s.size();

        int o = 0;
        int c = 0;
        for (int i = n - 1; i > 0; i--) {
            if (((s[i] - '0') + c) % 2) {
                o += 2;
                c = 1;
            } else {
                o++;
            }
        }

        return o + c;
    }
};