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