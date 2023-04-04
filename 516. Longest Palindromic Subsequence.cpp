class Solution
{
public:
    /*
    Approach:

    Same as Longest Common Subseqence in string just the string and check for subsequence.(Not intuitive)

    */
    int longestPalindromeSubseq(string s)
    {
        string y = s;
        reverse(y.begin(), y.end());
        int n = s.size();
        int m = y.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                if (s[i] == y[j])
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