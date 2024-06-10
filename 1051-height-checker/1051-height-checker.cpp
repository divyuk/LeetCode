class Solution {

    void bubbleSort(vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < n - i - 1; ++j) {
                if (arr[j] > arr[j + 1]) 
                    swap(arr[j], arr[j + 1]);
            }
        }
    }

public:
    int heightChecker(vector<int>& heights) {
     
        vector<int> sortedHeights = heights;
        bubbleSort(sortedHeights);
        int count = 0;
        for (int i = 0; i < sortedHeights.size(); ++i) {
            if (heights[i] != sortedHeights[i]) {
                count += 1;
            }
        }
        return count;
    }
};