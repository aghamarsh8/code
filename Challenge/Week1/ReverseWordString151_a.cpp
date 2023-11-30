/**
 * @file ReverseWordString151_a.cpp
 * @author Aghamarsh Varanasi
 * @brief 
 * String stream based solution for the following problem in Leet code as part of Top Interview 150 - Study Plan
 * 151. Reverse Words in a String
 * https://leetcode.com/problems/reverse-words-in-a-string/description/?envType=study-plan-v2&envId=top-interview-150
 * 
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
    string reverseWords(string s) {
        stringstream ss (s);
        string result = "";
        while (!ss.eof()) {
            string word;
            ss >> word;

            if (word == "" || word == " " || word == "    ") {
                continue;
            }

            if (!result.length()) {
                result = word;
            } else {
                result = word + " " + result;
            }
        }
        return result;
    }
};

int main () {
    Solution s;
    string str = "   the  sky   is blue   ";
    cout << "\"" <<s.reverseWords(str) << "\"";
    cout << std::endl << str.length();

    return 0;
}