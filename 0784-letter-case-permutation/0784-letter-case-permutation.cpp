#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    void recursively(string s, vector<string>& letterPerm, int index) {
        if (index == s.length()) {
            letterPerm.push_back(s);
            return;
        }

        // Recur with current character as lowercase
        recursively(s, letterPerm, index + 1);

        // If the current character is a letter, change case and recurse
        if (isalpha(s[index])) {
            s[index] = islower(s[index]) ? toupper(s[index]) : tolower(s[index]);
            recursively(s, letterPerm, index + 1);
        }
    }

    vector<string> letterCasePermutation(string s) {
        vector<string> letterPerm;
        recursively(s, letterPerm, 0);
        return letterPerm;
    }
};
