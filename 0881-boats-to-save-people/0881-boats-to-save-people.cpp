class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        
        sort(people.begin(), people.end()); 
        
        int boats = 0; 
        int n = people.size(); 
        int i = 0, j = n-1;
        
        while (i <= j) {
            boats++; 
            if (people[i] + people[j] <= limit) {
                i++; j--;
            }
            else {
                j--; 
            }
        }
        
        return boats; 
    }
    
    /*
        1 4 2 5
        1 2 4 5
        6
        1 2 -->  I
        4   --> II
        5   --> III
        
        3 2 2 1
        
        1 2 2 3
        
        3 5 3 4
        5
        
        
        
        
    */
};