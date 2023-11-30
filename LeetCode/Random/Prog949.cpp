/**
 * @file Prog949.cpp
 * @author Aghamarsh Varanasi
 * @brief 
 * This is a solution for the following problem in Leet code
 * 949. Largest Time for Given Digits
 * https://leetcode.com/problems/largest-time-for-given-digits/description/
 * @version 0.1
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

    bool isValidTime(int time[4]) {
        if (time[0] == 2 && time[1] <= 3 && time[2] <=5) {
            return true;
        } else if(time[0] < 2 && time[2] <= 5) {
            return true;
        }

        return false;
    }

    string toTimeString (int time[4]) {
        return to_string(time[0]) + to_string(time[1])+":"+ to_string(time[2]) + to_string(time[3]);
    }

    int compare(int t1[4], int t2[4]) {
        string a = this->toTimeString(t1);
        string b = this->toTimeString(t2);

        return a <= b;
    }

    string largestTimeFromDigits(vector<int>& arr) {
        int time[4] = {0,0,0,0};
        string sTime = "";
        int resTime[4] = {0,0,0,0};
        vector<int> t = {1,2,3,4};
        vector<vector<int>> possibilities = this->permute(t);

        for (int i = 0; i < possibilities.size(); i++) {
            time[0] = arr[possibilities[i][0]-1];
            time[1] = arr[possibilities[i][1]-1];
            time[2] = arr[possibilities[i][2]-1];
            time[3] = arr[possibilities[i][3]-1];

            if (this->isValidTime(time)) {
                if (this->compare(resTime, time)) {
                    resTime[0] = time[0];
                    resTime[1] = time[1];
                    resTime[2] = time[2];
                    resTime[3] = time[3];

                    sTime = this->toTimeString(time);
                }
            }
        }

        return sTime;
    }
};

int main() {
    Solution sl;
    vector<int> input = {1,2,3,4};
    cout << sl.largestTimeFromDigits(input) << endl;
}