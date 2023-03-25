class solution
{
public:
    int longestCommonSubsequence_Memoization(string &text1, string &text2, int index1, int index2, vector<vector<int>> &dp)
    {
        if (index1 < 0 || index2 < 0)
            return 0;
        if (dp[index1][index2] != -1)
            return dp[index1][index2];
        if (text1[index1] == text2[index2])
            return dp[index1][index2] = 1 + helper(text1, text2, index1 - 1, index2 - 1, dp);
        else
        {
            return dp[index1][index2] = max(helper(text1, text2, index1, index2 - 1, dp), helper(text1, text2, index1 - 1, index2, dp));
        }
    }

    int longestCommonSubsequence_Tablation(string text1, string text2)
    {
        int i1 = text1.size();
        int i2 = text2.size();
        vector<vector<int>> dp(i1 + 1, vector<int>(i2 + 1, 0));
        for (int index1 = 1; index1 <= i1; index1++)
        {
            for (int index2 = 1; index2 <= i2; index2++)
            {
                if (text1[index1 - 1] == text2[index2 - 1])
                    dp[index1][index2] = 1 + dp[index1 - 1][index2 - 1];
                else
                {
                    dp[index1][index2] = max(dp[index1][index2 - 1], dp[index1 - 1][index2]);
                }
            }
        }
        return dp[i1][i2];
    }

    int longestCommonSubsequence_SpaceOptimised(string text1, string text2)
    {
        int i1 = text1.size();
        int i2 = text2.size();
        vector<int> prev(i2 + 1, 0);
        vector<int> curr(i2 + 1, 0);
        for (int index1 = 1; index1 <= i1; index1++)
        {
            for (int index2 = 1; index2 <= i2; index2++)
            {
                if (text1[index1 - 1] == text2[index2 - 1])
                    curr[index2] = 1 + prev[index2 - 1];
                else
                {
                    curr[index2] = max(curr[index2 - 1], prev[index2]);
                }
            }
            prev = curr;
        }
        return curr[i2];
    }
};