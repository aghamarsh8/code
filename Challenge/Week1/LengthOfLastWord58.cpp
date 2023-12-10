/**
 * @file LengthOfLastWord58.cpp
 * @author Aghamarsh Varanasi
 * @brief Solution for the following problem in Leet code as part of Top Interview 150 - Study Plan
 * 58. Length of Last Word
 * https://leetcode.com/problems/length-of-last-word/description/?envType=study-plan-v2&envId=top-interview-150
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
    int lengthOfLastWord(string s) {
        int wordLength = 0;
        for(int itr = s.length() -1; itr >=0; itr --) {
            if (isalpha(s[itr])) {
                wordLength ++;
            } else {
                if (wordLength) {
                    break;
                }
            }
        }

        return wordLength;
    }
};


int main () {
    Solution s;
    cout << s.lengthOfLastWord(" hellow www world  lol ");
    return 0;
}