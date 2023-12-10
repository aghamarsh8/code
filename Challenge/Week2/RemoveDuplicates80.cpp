/**
 * @file RemoveDuplicates80.cpp
 * @author Aghamarsh Varanasi
 * @brief Solution for the following problem in Leet code as part of Top Interview 150 - Study Plan
 * 80. Remove Duplicates from Sorted Array II
 * https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description/?envType=study-plan-v2&envId=top-interview-150
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
        int lastElem = nums[0];
        int count = 0;        
        
        for(int i = 1; i < nums.size(); i++)
        {
            if (nums[i] != lastElem)
            {
                nums[++k] = nums[i];
                lastElem = nums[i];
                count = 0;
            } else {
                count ++;
                if (count == 1) {
                    nums[++k] = nums[i];
                }
            }
        }
        return k+1;
    }

    void print_array(vector<int> nums, int i, int k, int lastElem, int count) {
        for (int itr = 0; itr < nums.size(); itr++) {
        cout << nums[itr] << " ";
        }
        cout << endl;
        cout << " i " << i << " k: " << k << " lastElem: "<< lastElem << " count: " << count;
        cout << endl << endl;
    }
};

int main () {
    Solution s;
    vector<int> n = {1,2,2,2,2,3,3,3,4,4,4,5,5,6,6,7};
    int l = s.removeDuplicates(n);

    cout <<l;
    cout << "\nArray content\n";

    for (int i = 0; i < l; i++) {
        cout << n[i] << " ";
    }
    cout << endl;
    return 0;
}