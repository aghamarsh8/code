/**
 * @file ZigZag6.cpp
 * @author Aghamarsh Varanasi
 * @brief 
 * This is a solution for the following problem in Leet code as part of Top Interview 150 - Study Plan 
 * 6. Zigzag Conversion
 * https://leetcode.com/problems/zigzag-conversion/description/?envType=study-plan-v2&envId=top-interview-150
 * @version 1.0
 * @date 2023-11-30
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        string result = "";
        std::vector<bool> visited(s.length());
        int steps = 0;

        // numRows is 1 return the original string
        if (numRows == 1) {
            return s;
        }

        // for every step calculate the string
        while (steps < numRows) {
            int increment = 0;
            int direction = true;

            for(int itr = steps; itr < s.length(); itr += increment) {
                if (!visited[itr]) {
                    result += s[itr];
                    visited[itr] = true;
                }
                
                // downward direction of wave
                if (direction) {
                    increment = 2 *(numRows - steps - 1);
                }
                // upward direction of wave
                else {
                    increment = 2 * steps;
                }

                // reverse the direction
                direction = !direction;
            }
            steps++;
        }

        return result;
    }
};

int main () {
    Solution s;
    string str = "PAYPALISHIRING";
    int numRows = 3;
    cout << s.convert(str, numRows);
    return 0;
}