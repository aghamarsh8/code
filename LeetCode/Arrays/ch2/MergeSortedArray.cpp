class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int i = 0;
        int j = 0;

        int a = 0;

        while (i < m && j < n)
        {
            if (nums2[j] < nums1[i])
            {
                for (int k = m + n - 1 - j; k > a; k--)
                    nums1[k] = nums1[k - 1];

                nums1[a++] = nums2[j++];
                i++;
                m++;
            }
            else
            {
                a++;
                i++;
            }
        }

        while (j < n)
        {
            nums1[a++] = nums2[j++];
        }
    }
};