#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasDuplicate(map<int, vector<int>> nums, int k) {
        for(auto itr = nums.begin(); itr != nums.end(); itr ++) {
            if(itr->second.size() >= 2) {
                for(int i = 0; i < (itr->second.size() - 1); i++) {
                    if((itr->second[i+1] - itr->second[i]) <= k)
                        return true;
                }
            }
        }
        return false;
    }
    
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, vector<int>> refactor;
        for(int i=0; i < nums.size(); i ++) {
            refactor[nums[i]].push_back(i);   
        }
        
        return hasDuplicate(refactor, k);
    }
};

int main() {
    Solution s;
    vector<int> input{1,2,3,1,2,3};
    cout << " Ans: " << s.containsNearbyDuplicate(input, 2);
}