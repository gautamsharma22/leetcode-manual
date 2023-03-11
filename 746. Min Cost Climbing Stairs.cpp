// Fine Tuning, SC ->O(1)
// Eliminate use of arrays
class Solution1
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int cost1 = cost[0];
        int cost2 = cost[1];
        int n = cost.size();
        if (n <= 2)
            return min(cost1, cost2);
        for (int i = 2; i < n; i++)
        {
            int mincost = cost[i] + min(cost1, cost2);
            cost1 = cost2;
            cost2 = mincost;
        }
        return min(cost1, cost2);
    }
};
// Top Down Memoization - O(n) 1ms, SC ->O(N)
// Use Recursion With Some Memory
class Solution2
{
public:
    int helper(vector<int> cost, vector<int> &dp, int n)
    {
        if (n < 2)
            return cost[n];
        if (dp[n] != -1)
            return dp[n];
        dp[n] = cost[n] + min(helper(cost, dp, n - 1), helper(cost, dp, n - 2));
        return dp[n];
    }
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        vector<int> dp(n + 1, -1);
        return min(helper(cost, dp, n - 1), helper(cost, dp, n - 2));
    }
};

// Bottom up tabulation - O(n) 1ms, SC ->O(N)
// No Use of Recursion
class Solution3
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        vector<int> dp(n + 1, -1);
        for (int i = 0; i < n; i++)
        {
            if (i < 2)
                dp[i] = cost[i];
            else
                dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
        }
        return min(dp[n - 1], dp[n - 2]);
    }
};