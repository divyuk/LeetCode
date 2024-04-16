class Solution {
    void merge(vector<pair<int, int>>& indexedNums, vector<pair<int, int>>& left,
               vector<pair<int, int>>& right, vector<int>& counts) {
        int i = 0, j = 0, k = 0;
        while (i < left.size() && j < right.size()) {
            if (left[i].first <= right[j].first) {
                indexedNums[k] = left[i];
                counts[left[i].second] += j;  // Increment count of smaller elements
                ++i;
            } else {
                indexedNums[k] = right[j];
                ++j;
            }
            ++k;
        }
        
        while (i < left.size()) {
            indexedNums[k] = left[i];
            counts[left[i].second] += j;  // Increment count of smaller elements
            ++i;
            ++k;
        }
        
        while (j < right.size()) {
            indexedNums[k] = right[j];
            ++j;
            ++k;
        }
    }
    void mergeSort(vector<pair<int, int>>& indexedNums, vector<int>& counts) {
        if (indexedNums.size() <= 1) return;
        
        int mid = indexedNums.size() / 2;
        vector<pair<int, int>> left(indexedNums.begin(), indexedNums.begin() + mid);
        vector<pair<int, int>> right(indexedNums.begin() + mid ,indexedNums.end());
        
        mergeSort(left, counts);
        mergeSort(right, counts);
        
        merge(indexedNums, left, right, counts);
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> counts(nums.size(), 0);
        vector<pair<int, int>> indexedNums(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            indexedNums[i] = {nums[i], i};
        }
        
        mergeSort(indexedNums, counts);
        return counts;
    }
    

    

};
