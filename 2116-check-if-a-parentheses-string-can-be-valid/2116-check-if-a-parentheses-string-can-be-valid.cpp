#include <string>
using namespace std;

class Solution {
public:
    bool canBeValid(string s, string locked) {
        int close_paranthesis = 0;
        int open_paranthesis = 0;
        int flip_allowed = 0;

        if (s.length() % 2 != 0) {
            return false;
        }

        for (int i = 0; i < s.length(); ++i) {
            if (locked[i] == '0') {
                flip_allowed++;
            } else {
                if (s[i] == '(') {
                    open_paranthesis++;
                } else {
                    close_paranthesis++;
                }
            }

            if (flip_allowed + open_paranthesis < close_paranthesis) {
                return false;
            }
        }

        close_paranthesis = 0;
        open_paranthesis = 0;
        flip_allowed = 0;

        for (int i = s.length() - 1; i >= 0; --i) {
            if (locked[i] == '0') {
                flip_allowed++;
            } else {
                if (s[i] == '(') {
                    open_paranthesis++;
                } else {
                    close_paranthesis++;
                }
            }

            if (flip_allowed + close_paranthesis < open_paranthesis) {
                return false;
            }
        }

        return true;
    }
};
