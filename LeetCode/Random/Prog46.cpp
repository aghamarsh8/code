/**
 * @file Prog46.cpp
 * @author Aghamarsh Varanasi
 * @brief 
 * This is a solution for the following problem in Leet code
 * 46. Permutations
 * https://leetcode.com/problems/permutations/description/
 * @version 1.0
 * @date 2023-11-30
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
     void swap(vector<int>& nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    void recFun (vector<int> &nums, int l, int r, vector<vector<int>>& out) {
        if (l == r) {
            // this->print(nums, 'p');
            out.push_back(nums);
        } else {
            for (int i = l; i <= r; i ++) {
                // this->print(nums, 'l');
                this->swap(nums, l, i);
                recFun(nums, l + 1, r, out);
                this->swap(nums, l, i);
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> out;
        this->recFun(nums, 0, nums.size() - 1, out);
        return out;
    }

    void print (vector<int> &nums, char c) {
        if(c == 'p') {
            cout << "Pushing :\n";
        } else if (c == 'l') {
            cout << "looping :\n";
        }
        
        for(int i =0 ; i < nums.size(); i++) {
            cout << nums[i] << " ";
        }
        cout << endl;
    }
};

int main () {
    Solution sl;
    vector<int> v = {1, 2, 3};
    sl.permute(v);
}