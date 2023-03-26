class Solution
{
public:
    int getMoneyAmount_Recursion(int start, int end)
    {
        int ans = INT_MAX;
        if (start >= end)
            return 0;
        for (int i = start; i <= end; i++)
        {
            int lower = i + helper(start, i - 1);
            int higher = i + helper(i + 1, end);
            ans = min(ans, max(lower, higher));
        }
        return ans;
    }
    int getMoneyAmount_Memoization(int start, int end, vector<vector<int>> &dp)
    {
        if (start >= end)
            return 0;
        if (dp[start][end] != -1)
            return dp[start][end];
        int ans = INT_MAX;
        for (int i = start; i <= end; i++)
        {
            int lower = i + helper(start, i - 1, dp);
            int higher = i + helper(i + 1, end, dp);
            ans = min(ans, max(lower, higher));
        }
        return dp[start][end] = ans;
    }
    int getMoneyAmount_Tablulation(int n)
    {
        int dp[n + 2][n + 2];
        memset(dp, 0, sizeof(dp));
        // vector<vector<int>> dp(n+2,vector<int>(n+2,0));
        for (int start = n; start >= 1; start--)
        {
            for (int end = start; end <= n; end++)
            {
                if (start == end)
                    continue;
                int ans = INT_MAX;
                for (int i = start; i <= end; i++)
                {
                    int lower = i + dp[start][i - 1];
                    int higher = i + dp[i + 1][end];
                    ans = min(ans, max(lower, higher));
                }
                dp[start][end] = ans;
            }
        }
        return dp[1][n];
    }
};