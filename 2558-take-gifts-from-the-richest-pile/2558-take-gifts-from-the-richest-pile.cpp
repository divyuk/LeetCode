class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        int n = gifts.size();

        // Create a copy of the gifts array and sort it
        vector<int> sortedGifts = gifts;
        sort(sortedGifts.begin(), sortedGifts.end());

        // Perform the operation k times
        for (int i = 0; i < k; i++) {
            int maxElement = sortedGifts[n - 1];
            sortedGifts.pop_back();

            // upper_bound returns the first element greater than
            // sqrt(maxElement)
            auto spotOfSqrt = upper_bound(sortedGifts.begin(),
                                          sortedGifts.end(), sqrt(maxElement));

            // Insert the square root value at the found position
            sortedGifts.emplace(spotOfSqrt, sqrt(maxElement));
        }

        // Calculate the sum of the remaining gifts in the array
        long long int numberOfRemainingGifts =
            accumulate(sortedGifts.begin(), sortedGifts.end(), 0LL);

        return numberOfRemainingGifts;
    }
};