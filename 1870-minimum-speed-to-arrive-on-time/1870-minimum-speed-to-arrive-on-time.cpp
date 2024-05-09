class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        const int maxSpeed = 1e7;
        int n = dist.size();

//         for (int speed = 1; speed <= maxSpeed; ++speed) {
//             double totalTime = 0;
            
//             for (int i = 0; i < n - 1; ++i) 
//                 totalTime += ceil(dist[i] / static_cast<double>(speed));
            
//             totalTime += dist[n - 1] / static_cast<double>(speed);

//             if (totalTime <= hour) return speed;
            
//         }
        
        int low = 1, high = maxSpeed, mid=0, result = -1;
        while(low<=high){
            int mid = low + (high-low) /2;
            

            double totalTime = 0;

            for (int i = 0; i < n - 1; ++i) 
                totalTime += ceil(dist[i] / static_cast<double>(mid));

            totalTime += dist[n - 1] / static_cast<double>(mid);

            if (totalTime <= hour){
                result = mid;
                high = mid-1;
            }
            else low = mid+1;
            
        }
        

        return result;
    }
};