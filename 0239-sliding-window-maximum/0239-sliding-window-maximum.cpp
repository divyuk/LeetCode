class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        deque<int>dq;
        
        int n = nums.size(),start=0,end=0;
        while(end!=n){
            while( !dq.empty() and dq.back() < nums[end] ) dq.pop_back();
            dq.push_back(nums[end]);    
            while(end-start+1==k){
                ans.push_back( dq.front() );
                if(dq.front() == nums[start]) dq.pop_front();
                start++;
            }
            end++;
        }
        return ans;
    }
};