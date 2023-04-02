class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans; 
        sort(intervals.begin(), intervals.end()); 
        
        int n = intervals.size(); 
        
        vector<int> temp; 
        
        int end = intervals[0][1]; 
        int start; 
        int j = 0; 
        for (int i = 1; i < n; i++) {
            start = intervals[i][0]; 
            
            if (end >= start) {
                end = max(end, intervals[i][1]); 
                
            }
            else {
                temp.push_back(intervals[j][0]); temp.push_back(end);
                end = max(end, intervals[i][1]) ;
                j = i;
                // i--;
                
                ans.push_back(temp); 
                temp.clear(); 
            }
        }
        if (j < n) {
            ans.push_back({intervals[j][0], end});
        }
        return ans; 
    }
};

// [[1,3],[2,6],[4,8],[8,10],[15,18]] 