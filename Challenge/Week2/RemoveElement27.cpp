/**
 * @file RemoveElement27.cpp
 * @author Aghamarsh Varanasi
 * @brief Solution for the following problem in Leet code as part of Top Interview 150 - Study Plan
 * 27. Remove Element
 * https://leetcode.com/problems/remove-element/description/?envType=study-plan-v2&envId=top-interview-150
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
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] != val)
            {
                if(i != k)
                    nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
};

int main () {
    Solution s;
    vector<int> n = {1,2,3,4,5};
    cout << s.removeElement(n, 3);
    return 0;
}