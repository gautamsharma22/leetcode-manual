class Solution
{
public:
    /*
    Approach:
     Same as prev question just used limits array
    */
    int helper(vector<int> &prices, int index, bool canBuy, int k, vector<vector<vector<int>>> &dp)
    {
        if (index >= prices.size())
            return 0;
        if (k == 0)
            return 0;
        if (dp[index][canBuy][k] != -1)
            return dp[index][canBuy][k];
        int profit = 0;
        if (canBuy)
        {
            int buyed = -prices[index] + helper(prices, index + 1, false, k, dp);
            int notbuyed = 0 + helper(prices, index + 1, true, k, dp);
            profit = max(buyed, notbuyed);
        }
        else
        {
            int sold = prices[index] + helper(prices, index + 1, true, k - 1, dp);
            int notsold = 0 + helper(prices, index + 1, false, k, dp);
            profit = max(sold, notsold);
        }
        return dp[index][canBuy][k] = profit;
    }

    int maxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(k + 1, -1)));
        return helper(prices, 0, true, k, dp);
    }

    int maxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(k + 1, 0)));
        for (int index = n - 1; index >= 0; index--)
        {
            for (int canBuy = 0; canBuy <= 1; canBuy++)
            {
                for (int limit = 1; limit <= k; limit++)
                {
                    int profit = 0;
                    if (canBuy)
                    {
                        int buyed = -prices[index] + dp[index + 1][false][limit];
                        int notbuyed = 0 + dp[index + 1][true][limit];
                        profit = max(buyed, notbuyed);
                    }
                    else
                    {
                        int sold = prices[index] + dp[index + 1][true][limit - 1];
                        int notsold = 0 + dp[index + 1][false][limit];
                        profit = max(sold, notsold);
                    }
                    dp[index][canBuy][limit] = profit;
                }
            }
        }
        return dp[0][1][k];
    }
};