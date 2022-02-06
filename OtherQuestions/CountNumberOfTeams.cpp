#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int eligibleSoldiers(vector<int>& rating, int j) {
        pair<int, int> before = {0,0};
        pair<int, int> after = {0,0};

        for(int i = 0; i < j; i++) {
            if(rating[i] < rating[j]) {
                before.first ++;
            } else {
                before.second ++;
            }
        }

        for(int i = j+1; i < rating.size(); i ++) {
            if(rating[i] < rating[j]) {
                after.first ++;
            } else {
                after.second ++;
            }
        }

        return (after.first * before.second) + (after.second * before.first);
    }

    int numTeams(vector<int>& rating) {
        int ans = 0;

        for(int i = 1; i < rating.size() - 1; i++) {
            ans += eligibleSoldiers(rating, i);
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> v {2,5,3,4,1};
    cout << "Ans :: " << s.numTeams(v) << endl;
}