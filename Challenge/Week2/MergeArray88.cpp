/**
 * @file MergeArray88.cpp
 * @author Aghamarsh Varanasi
 * @brief Solution for the following problem in Leet code as part of Top Interview 150 - Study Plan
 * 88. Merge Sorted Array
 * https://leetcode.com/problems/merge-sorted-array/description/?envType=study-plan-v2&envId=top-interview-150
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
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (m == 1 && n == 0) {
            return;
        } else {
            vector<int> temp(nums1);

            int itr = 0, itr1 = 0, itr2 = 0;

            while ((itr1 < m) && (itr2 < n)) {
                if(temp[itr1] < nums2[itr2]) {
                    nums1[itr++] = temp[itr1++];
                } else if(temp[itr1] > nums2[itr2]) {
                    nums1[itr++] = nums2[itr2++];
                } else {
                    nums1[itr++] = temp[itr1++];
                    nums1[itr++] = nums2[itr2++];
                }
            }

            while (itr1 < m) {
                nums1[itr++] = temp[itr1++];
            }

            while (itr2 < n) {
                nums1[itr++] = nums2[itr2++];
            }
        }
    }
};

int main () {
    Solution s;
    vector<int> n1 = {1,2,3,0,0};
    vector<int> n2 = {2,4};

    s.merge(n1, 3, n2, 2);
    for(int i = 0; i < n1.size(); i++) {
        cout << n1[i] << " ";
    }
    cout << endl;
    return 0;
}