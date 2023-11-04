class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>element_map;
        int n = nums.size();

        for(int i =0;i<n;i++){
            if(element_map.find(target-nums[i]) !=element_map.end() )
                return {element_map[target-nums[i]] , i};  
            element_map[nums[i]] = i;
        }
        return {};
    }
};