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