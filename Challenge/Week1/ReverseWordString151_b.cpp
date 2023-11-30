#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string result = "";
        int itr = 0;
        string word = "";

        // iterate through the string
        while (itr < s.length()) {
            if (s[itr] == ' ') {
                // word has ended, add the word to the result
                result = this->addWordToResult(result, word);
                word = "";
            } else {
                // add character to word
                word += s[itr];
            }
            itr ++;
        }

        // add last word to the result 
        result = this->addWordToResult(result, word);

        return result;
    }

    string addWordToResult (string s1, string s2) {
        if (s2.length() > 0) {
            if (s1.length() == 0) {
                s1 = s2;
            } else {
                s1 = s2 + " " + s1;
            }
        }
        return s1;
    }
};

int main () {
    Solution s;
    string str = "  the sky  is blue ";
    cout << "\"" <<s.reverseWords(str) << "\"";

    return 0;
}