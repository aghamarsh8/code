/**
 * @file RemoveDuplicates26.cpp
 * @author Aghamarsh Varanasi
 * @brief Solution for the following problem in Leet code as part of Top Interview 150 - Study Plan
 * 26. Remove Duplicates from Sorted Array
 * https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/?envType=study-plan-v2&envId=top-interview-150
 * 
 * @version 1.0
 * @date 2023-12-10
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {     
        if(nums.size() == 0)
            return 0;
        
        int k = 0;              
        
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] != nums[k])
            {
                nums[++k] = nums[i];
            }
        }
        return k+1;
    }
};

int main () {
    Solution s;
    vector<int> n = {1,2,2,3,4,5,5,6,6,7};
    cout << s.removeDuplicates(n);
    return 0;
}