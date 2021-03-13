class Solution {
public:
    int numOfDigits(int n)
    {
        int digits =0;
        while(n)
        {
            n = n/10;
            digits++;
        }
        return digits;
    }

    int findNumbers(vector<int>& nums) {
        int num =0;
        for(int i=0;i<nums.size();i++)
        {
            if(numOfDigits(nums[i]) % 2 == 0)
                num ++;
        }
        return num;
    }
};