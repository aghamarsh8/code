/**
 * @file MostBeautifulItem.cpp
 * @author Aghamarsh Varanasi
 * @brief 
 * @version 0.1
 * @date 2023-11-30
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        map<int, int> maxBeauty;
        map<pair<int,int>, int> beautyIndex;
    
        for(int i = 0; i < items.size(); i++) {
            if(maxBeauty[items[i][0]] < items[i][1]) {
                maxBeauty[items[i][0]] = items[i][1];
            }
        }

        vector<int> ans;
        for(int i = 0; i < queries.size(); i++) {
            int a = 0;
            try {
                a = maxBeauty.at(queries[i]);
            } catch (...) {
                
            }
            ans.push_back(a);
        }
        return ans;
    }
};