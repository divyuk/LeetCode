class Solution {
public:
    int helper(vector<int>& nums, int k) {
        int left = 0, right = 0;
        map<int,int> map;
        int cnt = 0;
        int n = nums.size();
        while(right < n) {
            map[nums[right]]++;

            while(map.size() > k) {
                map[nums[left]]--;

                if(map[nums[left]] == 0)
                    map.erase(nums[left]);

                left++;
            }
            
            cnt += right - left + 1;
            right++;
        }

        return cnt;
    }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return helper(nums, k) - helper(nums, k - 1);
    }
};