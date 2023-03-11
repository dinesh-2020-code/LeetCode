class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        int n= nums.size();
        
        for(int i=0; i<n; i++)
        {
            if(nums[i]>n || nums[i]<=0) continue;
            
            while(nums[i]>0 && nums[i]<=n && nums[i]!=i+1)
            {
                if(nums[nums[i]-1] == nums[i]) break;   
                swap(nums[i], nums[nums[i]-1]);
            }
                
        }
        
        bool flag= true;
        for(int i=0; i<n; i++)
        {
            if(nums[i]==i+1)
                continue;
            else
            {
                return i+1;
            }
        }
        return n+1;
    }
};