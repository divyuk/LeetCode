class Solution {
public:
    string frequencySort(string s) {
        string res = "";
        int n = s.size();
        unordered_map<char, int> count;

        // Count the frequency of each character
        for (char c : s) {
            count[c]++;
        }

        // Find the maximum frequency
        int maxFreq = 0;
        for (const auto& entry : count) {
            maxFreq = max(maxFreq, entry.second);
        }

        // Create a bucket to store characters based on their frequency
        vector<vector<char>> buckets(maxFreq + 1);

        // Place characters into the corresponding bucket based on their frequency
        for (const auto& entry : count) {
            buckets[entry.second].push_back(entry.first);
        }

        // Build the result string by appending characters from buckets
        for (int i = maxFreq; i > 0; --i) {
            for (char c : buckets[i]) {
                res += string(i, c);
            }
        }

        return res;
    }
};