#include <bits/stdc++.h>
int helper(vector<int> &weight, vector<int> &value, int index, int maxWeight)
{
    if (index == 0)
    {
        if (weight[index] <= maxWeight)
            return value[0];
        else
            return 0;
    }
    int include = 0;
    if (weight[index] <= maxWeight)
        include = value[index] + helper(weight, value, index - 1, maxWeight - weight[index]);
    int exclude = 0 + helper(weight, value, index - 1, maxWeight);
    return max(include, exclude);
}
int helper2(vector<int> &weight, vector<int> &value, int index, int maxWeight, vector<vector<int>> &dp)
{
    if (index == 0)
    {
        if (weight[index] <= maxWeight)
            return value[0];
        else
            return 0;
    }
    if (dp[index][maxWeight] != -1)
        return dp[index][maxWeight];
    int include = 0;
    if (weight[index] <= maxWeight)
        include = value[index] + helper2(weight, value, index - 1, maxWeight - weight[index], dp);
    int exclude = 0 + helper2(weight, value, index - 1, maxWeight, dp);
    dp[index][maxWeight] = max(include, exclude);
    return dp[index][maxWeight];
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));
    return helper2(weight, value, n - 1, maxWeight, dp);
}