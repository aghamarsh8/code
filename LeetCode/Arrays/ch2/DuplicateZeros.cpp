class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int len = arr.size();
        for(int i = len-2; i >= 0; i --)
        {
            if(arr[i] == 0)
            {
                for(int j = len - 1; j > i ; j --)
                {
                    arr[j] = arr[j-1];
                }
            }
        }
    }
};