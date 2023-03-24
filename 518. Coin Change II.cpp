class Solution
{
public:
    int change_Recursion(vector<int> &coins, int amount, int index)
    {
        if (amount == 0)
            return 1;
        if (index < 0 || amount < 0)
            return 0;
        int include = helper(coins, amount - coins[index], index); // we can use same coin n number of times so no need to change index;
        int exclude = helper(coins, amount, index - 1);
        return include + exclude;
    }
    int change_Memoization(vector<int> &coins, int amount, int index, vector<vector<int>> &dp)
    {
        if (index == coins.size() || amount < 0)
            return 0;
        if (amount == 0)
            return 1;
        if (dp[index][amount] != -1)
            return dp[index][amount];
        int include = helperMem(coins, amount - coins[index], index, dp);
        int exclude = helperMem(coins, amount, index + 1, dp);
        return dp[index][amount] = include + exclude;
    }
    int change_Tabulation(vector<int> &coins, int amount_)
    {
        int n = coins.size();
        vector<vector<int>> dp(n + 2, vector<int>(amount_ + 2, 0));
        for (int i = 0; i < dp.size(); i++)
        {
            dp[i][0] = 1;
        }
        for (int index = n - 1; index >= 0; index--)
        {
            for (int amount = 1; amount <= amount_; amount++)
            {
                dp[index][amount] = dp[index + 1][amount];
                if (amount - coins[index] >= 0)
                {
                    int include = dp[index][amount - coins[index]];
                    dp[index][amount] += dp[index][amount - coins[index]];
                }
            }
        }
        return dp[0][amount_];
    }
    int change_SpaceOptimised(int amount_, vector<int> &coins)
    {
        int n = coins.size();
        vector<int> next(amount_ + 2, 0);
        vector<int> curr(amount_ + 2, 0);
        next[0] = 1;
        curr[0] = 1;
        for (int index = n - 1; index >= 0; index--)
        {
            for (int amount = 1; amount <= amount_; amount++)
            {
                curr[amount] = next[amount];
                if (amount - coins[index] >= 0)
                {
                    int include = curr[amount - coins[index]];
                    curr[amount] += curr[amount - coins[index]];
                }
            }
            next = curr;
        }
        return curr[amount_];
    }
};