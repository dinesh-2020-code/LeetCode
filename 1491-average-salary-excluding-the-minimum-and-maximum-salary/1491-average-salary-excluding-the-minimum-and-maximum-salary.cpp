class Solution {
public:
    double average(vector<int>& salary) {
        int size = salary.size(); 
        int max_salary = INT_MIN, min_salary = INT_MAX; 
        for (int x : salary) {
            max_salary = max(max_salary, x); 
            min_salary = min(min_salary, x); 
        }
        
        int sum = 0; 
        for (int x : salary) {
            if (x != max_salary && x != min_salary)
            {
                sum += x; 
            }
        }
        cout << min_salary << " "  << max_salary << endl; 
        return ((double)sum / (size - 2)) ;
    }
};