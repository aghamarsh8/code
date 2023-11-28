/**
 * @file FirstOccurrenceStr28.cpp
 * @author Aghamarsh Varanasi
 * @brief 
 * This is a solution for the following problem in Leet code as part of Top Interview 150 - Study Plan 
 * 28. Find the Index of the First Occurrence in a String
 * https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/?envType=study-plan-v2&envId=top-interview-150
 * 
 * @version 1.0
 * @date 2023-11-28
 * 
 * @copyright Copyright (c) 2023
 * All rights reserved
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        for (int itr = 0; itr < haystack.length(); itr++) {
            int itr1 = 0;

            // check if character in haystack and needle are the same
            while (haystack[itr + itr1] == needle[itr1] && itr1 < needle.length()) {
                itr1 ++;
            }

            // if we are end of needle, found a match 
            if (itr1 == needle.length()) {
                return itr;
            }
        }

        return -1;
    }
};

int main () {
    Solution s;
    std::string haystack = "aba";
    std::string needle = "b";
    cout << s.strStr(haystack, needle);
    return 0;
}