class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int n = nums.size();
        map<int,int>freq;
        
        for(int i =0;i<n;i++) freq[nums[i]]++;
        int cnt=0,ans=0;
        for(auto it :freq){
            ans=max(ans,it.second);
        }
      for(auto it :freq){
            if(it.second == ans)
                cnt+=it.second;
        }
        return cnt;
    }
};