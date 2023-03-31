class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans;
        for(int i=0;i<=n;i++){
            
            int num =i;
            
            int c=0;
            while(num){
                num=(num&num-1);
                c++;
                cout<<num<<" ";
            }
            ans.emplace_back(c);  
        }
        return ans;
    }
};