class Solution
{
public:
    int getMoneyAmount_Recursion(int start, int end)
    {
        // Base Case
        if (start >= end)
            return 0;
        int ans = INT_MAX;
        // iterate from 1-N and check who provides minimum ans.
        for (int i = start; i <= end; i++)
        {
            int lower = i + helper(start, i - 1);
            int higher = i + helper(i + 1, end);
            int currentAns = max(lower, higher); // Assuming the worst case.
            ans = min(ans, currentAns);          // If current guess (i) charges minimum $ then update the minimum.
        }
        return ans;
    }
    int getMoneyAmount_Memoization(int start, int end, vector<vector<int>> &dp)
    {
        // Same Approach as above just store and return values from DP array.
        if (start >= end)
            return 0;
        if (dp[start][end] != -1)
            return dp[start][end];
        int ans = INT_MAX;
        for (int i = start; i <= end; i++)
        {
            int lower = i + helper(start, i - 1, dp);
            int higher = i + helper(i + 1, end, dp);
            int currentAns = max(lower, higher);
            ans = min(ans, currentAns);
        }
        return dp[start][end] = ans;
    }
    int getMoneyAmount_Tablulation(int n)
    {
        int dp[n + 2][n + 2];
        memset(dp, 0, sizeof(dp)); // Improves runtime :>)
        // vector<vector<int>> dp(n+2,vector<int>(n+2,0)); //We can Use vector also...
        
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
                    int currentAns = max(lower, higher);
                    ans = min(ans, currentAns);
                }
                dp[start][end] = ans;
            }
        }
        return dp[1][n];
    }
};