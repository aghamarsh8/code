class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result(nums.size());
        
        int i =0;
        for(; i < nums.size() ; i++)
        {
            if(nums[i] >= 0)
                break;
        }
        int n = 0;
        if(i > 0)
        {
            int j = i-1;
            
            while(i < nums.size() && j >= 0)
            {
                if(nums[i] > -nums[j])
                {
                    result[n++]=(nums[j]*nums[j]);
                    j --;
                }
                else 
                {
                    result[n++]=(nums[i]*nums[i]);
                    i ++;
                }    
            }
            
            while(j >= 0)
            {
                result[n++]=(nums[j]*nums[j]);
                j --;
            }
            
            while(i < nums.size())
            {
                result[n++]=(nums[i]*nums[i]);
                i ++;
            }
        }
        else
        {
            for(int i=0; i < nums.size(); i++)
            {
                result[n++]=(nums[i]*nums[i]);
            }
        }
        
        return result;
    }
};