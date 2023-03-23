//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
int median(vector<vector<int>> &matrix, int R, int C){
        vector<int> ans;
        
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                ans.push_back(matrix[i][j]);
            }
        }
        
        sort(ans.begin(),ans.end());
        int s = 0, e = ans.size()-1;
        int m = (s+e)/2;
        return ans[m];
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    }
    return 0;
}
// } Driver Code Ends