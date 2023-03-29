class Solution
{
public:
    int numTrees_Recursion(int n)
    {
        if (n <= 1)
            return 1;
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            int left = numTrees_Recursion(i - 1);
            int right = numTrees_Recursion(n - i);
            ans += left * right;
        }
        return ans;
    }
    int numTrees_Memoization(int n, vector<int> &dp)
    {
        if (n <= 1)
            return 1;
        if (dp[n] != -1)
            return dp[n];
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            int left = numTrees_Memoization(i - 1, dp);
            int right = numTrees_Memoization(n - i, dp);
            ans += left * right;
        }
        return dp[n] = ans;
    }
    int numTrees_Tabulation(int n)
    {
        vector<int> dp(n + 1, 0);
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                int left = dp[j - 1];
                int right = dp[i - j];
                dp[i] += left * right;
            }
        }
        return dp[n];
    }
    // Simply calculate Catlan number...
    int numTrees(int n)
    {
        long Catalan = 1;
        for (int i = 0; i < n; ++i)
        {
            Catalan = Catalan * 2 * (2 * i + 1) / (i + 2);
        }
        return Catalan;
    }
};