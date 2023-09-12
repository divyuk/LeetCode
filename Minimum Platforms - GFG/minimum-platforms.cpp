//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
        // Store the arrival and departure time
        vector<pair<int, int> > arr2(n);
     
        for (int i = 0; i < n; i++) {
            arr2[i] = { arr[i], dep[i] };
        }
     
        // Sort arr2 based on arrival time
        sort(arr2.begin(), arr2.end());
     
        priority_queue<int, vector<int>, greater<int> > p;
        int count = 1;
        p.push(arr2[0].second);
     
        for (int i = 1; i < n; i++) {
     
            // Check if arrival time of current train
            // is less than or equals to departure time
            // of previous train
            if (p.top() >= arr2[i].first) {
                count++;
            }
            else {
                p.pop();
            }
            p.push(arr2[i].second);
        }
     
        // Return the number of trains required
        return count;
    }
};


//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}
// } Driver Code Ends