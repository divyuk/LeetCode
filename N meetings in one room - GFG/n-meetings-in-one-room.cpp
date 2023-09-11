//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        
        vector<pair<int,int>> meetings(n);
        for(int i =0  ; i<n ; i++){
            meetings[i].first = end[i];
            meetings[i].second = start[i];
        }
        // 1. Sort based on the ending time as in future we will have more number of chances to watch movies
        sort(meetings.begin() , meetings.end());

        // 2. Compared with the arrival of next movie so that to know if we can watch that movie or not.
        int numberOfMeetings =1 ;
        int endingMeeting = meetings[0].first;
        for(int i =1  ; i<n ; i++){
            if(endingMeeting < meetings[i].second ){
                endingMeeting = meetings[i].first;
                numberOfMeetings++;
                
            }
        }
        
        return numberOfMeetings;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends