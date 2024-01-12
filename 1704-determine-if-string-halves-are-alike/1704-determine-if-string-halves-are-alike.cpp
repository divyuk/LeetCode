class Solution {
public:
    bool halvesAreAlike(string s) {
        // Function to count vowels in a string
        auto countVowels = [](const string& str) {
            unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
            int count = 0;
            for (char ch : str) {
                if (vowels.count(ch) > 0) {
                    count++;
                }
            }
            return count;
        };

        int halfSize = s.size() / 2;

        // Count vowels in the first and second halves using the helper function
        int cnt1 = countVowels(s.substr(0, halfSize));
        int cnt2 = countVowels(s.substr(halfSize));

        // Check if the counts are equal
        return cnt1 == cnt2;
    }
};