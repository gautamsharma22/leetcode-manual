class Solution
{
public:
    int helper(int index1, int index2, vector<int> &nums1, vector<int> &nums2, vector<vector<int>> &dp)
    {
        if (index1 >= nums1.size() || index2 >= nums2.size())
        {
            return 0;
        }
        if (dp[index1][index2] != -1)
        {
            return dp[index1][index2];
        }
        if (nums1[index1] == nums2[index2])
        {
            return dp[index1][index2] = 1 + helper(index1 + 1, index2 + 1, nums1, nums2, dp);
        }
        return dp[index1][index2] = max(helper(index1 + 1, index2, nums1, nums2, dp), helper(index1, index2 + 1, nums1, nums2, dp));
    }
    int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                if (nums1[i] == nums2[j])
                {
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                }
                else
                {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }
        return dp[0][0];
    }
};