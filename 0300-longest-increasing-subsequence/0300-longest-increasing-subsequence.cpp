class Solution {
private:
    int binarySearch(vector<int>& sub, int num) {
        int left = 0;
        int right = sub.size() - 1;
        int mid;
        while (left < right) {
            mid = left + (right - left) / 2;
            if (sub[mid] == num) return mid;
            if (sub[mid] < num)  left = mid + 1;
            else right = mid;     
        }
        return left;
    }
    
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> sub;
        sub.push_back(nums[0]);

        for (int i = 1; i < nums.size(); i++) {
            int num = nums[i];
            if (sub.back() < num ) {
                sub.push_back(num);
            } else {
                int j = binarySearch(sub, num); // find  ele that is greater than or equal to num and replace element with num
                sub[j] = num;
            }
        }

        return sub.size();
    }


};
