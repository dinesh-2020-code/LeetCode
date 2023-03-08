class Solution {
public:
    bool isPossible(vector<int>& time, int totalTrips, long long minTime) {
        
        long long int trips = 0; 
        
        for (int i = 0; i < time.size(); i++) {
            trips += minTime / time[i]; 
        }
        
        return (trips >= totalTrips); 
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        
        long long low = 0, high = INT_MIN, mid = 0; 
        for (int i = 0; i < time.size(); i++) 
            high = max(high, time[i] * 1ll); 
        
        high = (high * totalTrips); 
        while ((high - low) > 1) {
            mid = low + (high - low) / 2; 
            
            if (isPossible(time, totalTrips, mid)) 
                high = mid; 
            else 
                low = mid;
        }
        return high; 
    }
};