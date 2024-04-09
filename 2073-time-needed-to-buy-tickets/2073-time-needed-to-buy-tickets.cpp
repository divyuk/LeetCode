class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        
        queue<int> queue;

        for (int i = 0; i < tickets.size(); i++)  queue.push(i);
        

        int time = 0;

        while (!queue.empty()) {
          
            time++;

       
            int front = queue.front();
            queue.pop();

            // Buy
            tickets[front]--;

            // If person k bought all their tickets, return time
            if (k == front && tickets[front] == 0) {
                return time;
            }

           // Re-add the current index to the queue for the next iteration if there are still tickets
            if (tickets[front] != 0) {
                queue.push(front);
            }
        }

        return time;
    }
};