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

        // Create an unordered_map to store characters based on their frequency
        unordered_map<int, string> buckets;

        // Place characters into the corresponding bucket based on their frequency
        for (const auto& entry : count) {
            buckets[entry.second].append(entry.second, entry.first);
        }

        // Build the result string by appending characters from buckets
        for (int i = maxFreq; i > 0; --i) {
            if (buckets.find(i) != buckets.end()) {
                res += buckets[i];
            }
        }

        return res;
    }
};