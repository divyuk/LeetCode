class Solution {
public:
    int maximizeSquareArea(int numRows, int numCols, vector<int>& horizontalFences, vector<int>& verticalFences) {
        horizontalFences.push_back(1);
        horizontalFences.push_back(numRows);
        verticalFences.push_back(1);
        verticalFences.push_back(numCols);
        int hSize = horizontalFences.size();
        int vSize = verticalFences.size();
        sort(horizontalFences.begin(), horizontalFences.end());
        sort(verticalFences.begin(), verticalFences.end());

        set<int> horizontalDifferences;
        for (int i = hSize - 1; i >= 0; --i) {
            for (int j = 0; j < i; ++j) {
                int diff = horizontalFences[i] - horizontalFences[j];
                horizontalDifferences.insert(diff);
            }
        }

        vector<int> verticalDifferences;
        for (int i = vSize - 1; i >= 0; --i) {
            for (int j = 0; j < i; ++j) {
                int diff = verticalFences[i] - verticalFences[j];
                verticalDifferences.push_back(diff);
            }
        }

        long long maxSquareArea = -1;
        sort(verticalDifferences.begin(), verticalDifferences.end());
        for (int i = verticalDifferences.size() - 1; i >= 0; --i) {
            if (horizontalDifferences.find(verticalDifferences[i]) != horizontalDifferences.end()) {
                maxSquareArea = verticalDifferences[i];
                break;
            }
        }

        int mod = 1e9 + 7;

        if (maxSquareArea != -1) {
            maxSquareArea = (maxSquareArea * maxSquareArea) % mod;
        }

        return static_cast<int>(maxSquareArea);
    }
};