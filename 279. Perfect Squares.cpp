class Solution
{
public:
    // Simple Recursive Solution Check if sqrt(i) can generate perfect number of squares or not where sqrt(i)<=n;
    int numSquaresRec(int n)
    {
        if (n == 0)
            return 0;
        int ans = INT_MAX;
        for (int i = 1; i * i <= n; i++)
        {
            ans = min(ans, 1 + numSquaresRec(n - i * i));
        }
        return ans;
    }
    // Memoization Solution
    int numSquaresMem(int n, vector<int> &dp)
    {
        if (n == 0)
            return 0;
        if (dp[n] != -1)
            return dp[n];
        int ans = n;
        for (int i = 1; i * i <= n; i++)
        {
            ans = min(ans, 1 + numSquaresMem(n - i * i, dp));
        }
        return dp[n] = ans;
    }
    // Tabulation 
    int numSquaresTab(int n)
    {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            for (int j = 1; j * j <= n; j++)
            {
                if (i - (j * j) >= 0)
                    dp[i] = min(dp[i], 1 + dp[i - (j * j)]);
            }
        }
        return dp[n];
    }
    int numSquares(int n)
    {
        // return numSquaresRec(n);

        // vector<int> dp(n+1,-1);
        // return numSquaresMem(n,dp);

        // numSquaresTab(n);
    }
};
// Tabulation Hints :

/*

1. For creating 0 number of perfect squares is zero;
2. For creating 1 number of perfect squares is one
3. By taking above situation in mind we initialize of a loop from 1 till n;
4. 


*/
