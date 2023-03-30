class Solution
{
public:
    /*
        Approach remains same as Buy and Sell Stock II.
        Add an Extra Constraint Limit and Convert 2D-DP to 3D-DP Same;
        This Can Be More Optimised but for now its okay...
    */
    int maxProfit_Memoization(vector<int> prices, int index, bool canBuy, int limit, vector<vector<vector<int>>> &dp)
    {
        if (index == prices.size())
            return 0;
        if (limit == 0)
            return 0;
        if (dp[index][canBuy][limit] != -1)
            return dp[index][canBuy][limit];
        int profit = 0;
        if (canBuy)
        {
            int buy = -prices[index] + maxProfit_Memoization(prices, index + 1, false, limit, dp);
            int dontBuy = 0 + maxProfit_Memoization(prices, index + 1, true, limit, dp);
            profit = max(buy, dontBuy);
        }
        else
        {
            int sell = prices[index] + maxProfit_Memoization(prices, index + 1, true, limit - 1, dp);
            int dontSell = 0 + maxProfit_Memoization(prices, index + 1, false, limit, dp);
            profit = max(sell, dontSell);
        }
        return dp[index][canBuy][limit] = profit;
    }
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, -1)));
        return maxProfit_Memoization(prices, 0, true, 2, dp);
    }
    int maxProfit_Tabulation(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
        for (int index = n - 1; index >= 0; index--)
        {
            for (int canBuy = 0; canBuy <= 1; canBuy++)
            {
                for (int limit = 1; limit <= 2; limit++)
                {
                    int profit = 0;
                    if (canBuy)
                    {
                        int buy = -prices[index] + dp[index + 1][false][limit];
                        int dontBuy = 0 + dp[index + 1][true][limit];
                        profit = max(buy, dontBuy);
                    }
                    else
                    {
                        int sell = prices[index] + dp[index + 1][true][limit - 1];
                        int dontSell = 0 + dp[index + 1][false][limit];
                        profit = max(sell, dontSell);
                    }
                    dp[index][canBuy][limit] = profit;
                }
            }
        }
        return dp[0][true][2];
    }
    int maxProfit_Tab_SpaceOp(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> next(2, vector<int>(3, 0));
        vector<vector<int>> curr(2, vector<int>(3, 0));
        for (int index = n - 1; index >= 0; index--)
        {
            for (int canBuy = 0; canBuy <= 1; canBuy++)
            {
                for (int limit = 1; limit <= 2; limit++)
                {
                    int profit = 0;
                    if (canBuy)
                    {
                        int buy = -prices[index] + next[false][limit];
                        int dontBuy = 0 + next[true][limit];
                        profit = max(buy, dontBuy);
                    }
                    else
                    {
                        int sell = prices[index] + next[true][limit - 1];
                        int dontSell = 0 + next[false][limit];
                        profit = max(sell, dontSell);
                    }
                    curr[canBuy][limit] = profit;
                }
            }
            next = curr;
        }
        return curr[true][2];
    }
};