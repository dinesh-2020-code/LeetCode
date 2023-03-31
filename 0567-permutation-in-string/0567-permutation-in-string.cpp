class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int k = s1.length(); 
        int mp[26] = {0}; 
        for (int i = 0; i < k; i++) 
            mp[s1[i] - 'a']++;


        int mp2[26] = {0};   
        for (int i = 0,j = 0; j < s2.size(); ) {
            mp2[s2[j] - 'a']++;

            if (j - i + 1 < k) //window size is smaller than k
                j++; 

            else if (j - i + 1 == k) { //window size is equal to k
                int count = 0; 
                for (int x = 0; x < 26; x++) {
                    if (mp[x] != mp2[x])
                    {
                            break;

                    }
                    else {
                        if (mp2[x] != 0 and mp[x] == mp2[x])
                            count += mp[x]; 
                    }
                }
                // cout << count << " " ;
                if (count == k)
                    return true; 

                mp2[s2[i] - 'a']--; 
                j++; i++;     

            }    
        }     


        return false; 
    }
};