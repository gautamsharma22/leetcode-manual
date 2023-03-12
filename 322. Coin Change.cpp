// Normal Recursion (Gives TLE)
class Solution
{
public:
    int helper(vector<int> &coins, int amount)
    {
        if (amount == 0)
            return 0;
        if (amount < 0)
            return INT_MAX;
        int mini = INT_MAX;
        for (auto i : coins)
        {
            int ans = helper(coins, amount - i);
            if (ans != INT_MAX)
                mini = min(mini, 1 + ans);
        }
        return mini;
    }
    int coinChange(vector<int> &coins, int amount)
    {
        int ans = helper(coins, amount);
        if (ans == INT_MAX)
            return -1;
        return ans;
    }
};
// DP + Memoization (Accepted)
class Solution2
{
public:
    int helper(vector<int> &coins, int amount, vector<int> &dp)
    {
        if (amount == 0)
            return 0;
        if (amount < 0)
            return INT_MAX;
        int mini = INT_MAX;
        if (dp[amount] != -1)
            return dp[amount];
        for (auto i : coins)
        {
            int ans = helper(coins, amount - i, dp);
            if (ans != INT_MAX)
                mini = min(mini, 1 + ans);
        }
        dp[amount] = mini;
        return mini;
    }
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> dp(amount + 1, -1);
        int ans = helper(coins, amount, dp);
        if (ans == INT_MAX)
            return -1;
        return ans;
    }
};
// Bottom Up (Tabulation) (Accepted)
class Solution3
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++)
        {
            for (int j = 0; j < coins.size(); j++)
            {
                if (i - coins[j] >= 0 && dp[i - coins[j]] != INT_MAX)
                {
                    dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
                }
            }
        }
        if (dp[amount] == INT_MAX)
            return -1;
        return dp[amount];
    }
};