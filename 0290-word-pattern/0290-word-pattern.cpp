class Solution {
public:
bool wordPattern(string pattern, string s) {
    unordered_map<char, string> m;
    unordered_map<string, char> m2;
    istringstream in(s);
    int i = 0;
    for (string word; in >> word; ++i) {
        if (i == pattern.size())
            return false;
        char c = pattern[i];
        if (!m.count(c) && !m2.count(word)) {
            m[c] = word;
            m2[word] = c;
        } else if (m[c] != word || m2[word] != c) {
            return false;
        }
    }
    if(i != pattern.size()) return false;
    return true;
}



};