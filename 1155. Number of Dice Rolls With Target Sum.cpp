class Solution
{
public:
    int numRollsToTarget_Recursion(int n, int k, int target)
    {
        if (target < 0)
            return 0;
        if (target == 0 && n != 0)
            return 0;
        if (n == 0 && target != 0)
            return 0;
        if (target == 0 && n == 0)
            return 1;
        int sum = 0;
        for (int i = 1; i <= k; i++)
        {
            sum = sum + numRollsToTarget(n - 1, k, target - i);
        }
        return sum;
    }
    long numRollsToTarget_Memoization(int n, int k, int target, vector<vector<int>> &dp)
    {
        if (target < 0)
            return 0;
        if (target == 0 && n != 0)
            return 0;
        if (n == 0 && target != 0)
            return 0;
        if (target == 0 && n == 0)
            return 1;
        if (dp[n][target] != -1)
            return dp[n][target];
        int sum = 0;
        for (int i = 1; i <= k; i++)
        {
            sum = (sum + helper(n - 1, k, target - i, dp)) % 1000000007;
        }
        return dp[n][target] = sum;
    }
    long numRollsToTarget_Tabulation(int dice, int k, int target_)
    {
        vector<vector<int>> dp(dice + 2, vector<int>(target_ + 2, 0));
        dp[0][0] = 1;
        for (int n = 1; n <= dice; n++)
        {
            for (int target = 1; target <= target_; target++)
            {
                int sum = 0;
                for (int i = 1; i <= k; i++)
                {
                    if ((target - i) >= 0)
                        sum = (sum + dp[n - 1][target - i]) % 1000000007;
                }
                dp[n][target] = sum;
            }
        }
        return dp[dice][target_];
    }
    int numRollsToTarget_SpaceOptimised(int dice, int k, int target_)
    {
        vector<int> prev(target_ + 2, 0);
        vector<int> curr(target_ + 2, 0);
        prev[0] = 1;
        for (int n = 1; n <= dice; n++)
        {
            for (int target = 1; target <= target_; target++)
            {
                int sum = 0;
                for (int i = 1; i <= k; i++)
                {
                    if ((target - i) >= 0)
                        sum = (sum + prev[target - i]) % 1000000007;
                }
                curr[target] = sum;
            }
            prev = curr;
        }
        return prev[target_];
    }
};