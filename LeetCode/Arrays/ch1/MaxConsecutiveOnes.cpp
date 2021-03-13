class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max_one = 0;
        int temp = 0;
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] == 1)
                temp ++;
            else
            {
                if(max_one < temp)
                {
                    max_one = temp;
                }    
               temp = 0;
            }
        }
        
        return max(max_one,temp);
    }
};