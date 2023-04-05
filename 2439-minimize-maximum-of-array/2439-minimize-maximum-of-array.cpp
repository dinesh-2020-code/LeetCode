class Solution {
public:
    bool isGood(int ans, vector <long long> v) {
        int n = v.size() ; 
        long long int cnt = INT_MIN; 
        for (int i = n -1; i >= 1; i--) {
            if (v[i] <= ans) {
                cnt = max(cnt, v[i]); 
                continue; 
            }
            long long  inc = v[i]-ans;
            
            v[i] = ans ;
            v[i-1] += inc;  
             

            cnt = max(cnt, v[i]) ;   
        }
        cnt = max(cnt, v[0]);
         
        return (cnt == ans); 
    }
    int minimizeArrayValue(vector<int>& nums) {
        int maxi = INT_MIN;
        for (auto it : nums) {
            maxi = max(maxi, it);
        }
        long long  start = -1, end = maxi, mid = 0;
        vector<long long> v(nums.begin(), nums.end()); 
        mid = start + (end - start) / 2; 
        while ((end - start) > 1) {
            if (isGood(mid, v)) {
                end  = mid; 
            }
            else 
                start = mid; 

            mid = start + (end - start) / 2;     
        } 

        return end; 
    }
};