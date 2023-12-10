/**
 * @file LengthOfPrefix14.cpp
 * @author Aghamarsh Varanasi
 * @brief Solution for the following problem in Leet code as part of Top Interview 150 - Study Plan
 * 14. Longest Common Prefix
 * https://leetcode.com/problems/longest-common-prefix/description/?envType=study-plan-v2&envId=top-interview-150
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
    string longestCommonPrefix(vector<string>& strs) {
        int numOfStrings = strs.size();
        if (numOfStrings == 1) {
            return strs[0];
        }
        
        int commonIndex = -1;
        for(int itr = 0; itr < strs[0].length(); itr ++) {
            char bench = strs[0][itr];
            
            for (int strIndex = 1; strIndex < numOfStrings; strIndex ++) {
                // index is not a match
                if (strs[strIndex][itr] != bench) {
                    break;
                } else {
                    if (numOfStrings -1 == strIndex) {
                        commonIndex ++;
                    }
                }
            }

            // last index was not a match
            if (itr > commonIndex) {
                break;
            }
        }

        if (commonIndex == -1) {
            return "";
        } else {
            return strs[0].substr(0, commonIndex+1);
        }
    }
};

int main () {
    Solution s;
    vector<string> strs = {"abcd", "abdr" , "abds", "abbaby"};
    cout << s.longestCommonPrefix(strs);
    return 0;
}