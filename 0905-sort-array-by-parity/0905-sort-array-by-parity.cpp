class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int>even;
        vector<int>odd;
        vector<int>ans;
        for(int i = 0 ; i<(int) A.size(); i++ )
        {
            if(A[i]%2==0)
                even.push_back(A[i]);
            else
                odd.push_back(A[i]);
        }
        for(int i = 0 ; i<(int) even.size(); i++ )
        {
                ans.push_back(even[i]);
        }
                
        for(int i = 0 ; i<(int) odd.size(); i++ )
            ans.push_back(odd[i]);
    
        return ans;
    }
};