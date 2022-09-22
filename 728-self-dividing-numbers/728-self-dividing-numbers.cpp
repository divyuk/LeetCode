class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int>ans;
        for(int i = left ; i<=right ; i++){  
            string s = to_string(i);
            if(s.find('0')!=-1) continue;
            int n = s.size();
            int j =0;
            bool flag=true;
            while(j<n){
                int div = s[j]-48;
                if(div!=0 and i%div!=0){
                    flag=false;
                    break;
                }
                j++;
            }
            if(flag)
                ans.push_back(i);
        }
        return ans;
    }
};