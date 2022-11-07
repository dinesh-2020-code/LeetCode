class Solution {
public:
    int maximum69Number (int num) {
        int ans = 0; 
        //converting num (integer) to string using stringstream
        stringstream str; 
        
        str << num; 
        
        string no;
        str >> no; 
         
        
        //we can use to_string() function to convert any datatype to string
        
        for (int i = 0; i < no.size(); i++) {
            if (no[i] == '6') {
                no[i] = '9'; 
                break;
            }
            
        }
        ans = stoi(no); 
        
        return ans; 
        
    }
};