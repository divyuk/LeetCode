typedef long long ll;
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        int m = meetings.size();
        sort(meetings.begin() , meetings.end());
        vector<int>roomUsedCount(n,0); // Each room is used 0 time in the begining
        vector<ll>lastAvailable(n,0);
        
 
        for(vector<int>&meet : meetings){
            int start = meet[0];
            int end   = meet[1];
            ll earlyEndRoomTime =LLONG_MAX;
            int EarlyEndRoom = 0;
            bool found = false;
            for(int room = 0; room < n ; room++){
                if(lastAvailable[room] <= start){
                    lastAvailable[room] = end;
                    roomUsedCount[room]++;
                    found = true;
                    break;
                }
                // mechanism to keep note of which room is going to finish early
                if(lastAvailable[room] < earlyEndRoomTime){
                    earlyEndRoomTime = lastAvailable[room]; // Store when its finishes
                    EarlyEndRoom = room; // Store the room number
                }
            }
            if(!found){
                lastAvailable[EarlyEndRoom] += (end - start);
                roomUsedCount[EarlyEndRoom]++;
            }
        }
        int resultRoom = -1;
        int maxUse     = 0;  
        for(int room = 0; room < n; room++) {
            if(roomUsedCount[room] > maxUse) {
                maxUse = roomUsedCount[room];
                resultRoom = room;
            }
        }

        return resultRoom;
    }
};