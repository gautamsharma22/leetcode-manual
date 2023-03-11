class Solution
{
public:
    // DP Day 1
    int fibn(int n, vector<int> &dp)
    {
        if (n == 0 || n == 1)
        {
            return n;
        }
        if (dp[n] != -1)
            return dp[n];
        dp[n] = fibn(n - 1, dp) + fibn(n - 2, dp);
        return dp[n];
    }
    int fib(int n)
    {
        vector<int> dp(n + 1, -1);
        return fibn(n, dp);
    }
};