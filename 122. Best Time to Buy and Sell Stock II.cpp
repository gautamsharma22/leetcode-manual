class Solution
{
public:
    /*
    Approach 1:

    1.) At any Day We have four Choices

        a)Buy
        b)Don't Buy
        c)Sell
        d)Don't Sell

    2.) We can only buy if we dont have any stock in portfolio say.
    And we Can only sell if we have stock.

    3.) If we are making buy desicion then we pass CanBuy to false; cause we can hold maximum of one shares at a time.

    4.) At any time if we are selling the stock then we pass CanBuy to True, Becuase now we can purchase antoher stock.

    5.) So further it is also divided in subproblem of take and not take, and return max between them.

    */
    int maxProfit_Recursion(vector<int> &prices, int index, bool canBuy)
    {
        if (index >= prices.size())
            return 0;
        int profit = 0;
        if (canBuy)
        {
            int buy = -prices[index] + maxProfit_Recursion(prices, index + 1, false); // Here we say buying stock will decrease our money / profit so we have considered buying as (-ve).
            int notBuy = maxProfit_Recursion(prices, index + 1, true);
            profit = max(buy, notBuy);
        }
        else
        {
            int sell = prices[index] + maxProfit_Recursion(prices, index + 1, true); // Here we say Selling stock will increase our money / profit so we have considered buying as (+ve).
            int notSell = maxProfit_Recursion(prices, index + 1, false);
            profit = max(sell, notSell);
        }
        return profit;
    }
    int maxProfit_Memoization(vector<int> &prices)
    {
        return maxProfit_Recursion(prices, 0, true);
    }
    /*
        Same Recursive approach just use cache or DP to store the previous calculated value.
    */
    int maxProfit_Memoization(vector<int> &prices, int index, bool canBuy, vector<vector<int>> &dp)
    {
        if (index >= prices.size())
            return 0;
        if (dp[index][canBuy] != -1)
            return dp[index][canBuy];
        int profit = 0;
        if (canBuy)
        {
            int buy = -prices[index] + maxProfit_Memoization(prices, index + 1, false, dp);
            int notBuy = maxProfit_Memoization(prices, index + 1, true, dp);
            profit = max(buy, notBuy);
        }
        else
        {
            int sell = prices[index] + helper(prices, index + 1, true, dp);
            int notSell = maxProfit_Memoization(prices, index + 1, false, dp);
            profit = max(sell, notSell);
        }
        return dp[index][canBuy] = profit;
    }
    int maxProfit(vector<int> &prices)
    {
        vector<vector<int>> dp(prices.size() + 1, vector<int>(2, -1));
        return maxProfit_Memoization(prices, 0, true, dp);
    }
    /*
        Approach will be same just calculate the profit from n-1 to 0 (Bottom Up)
    */
    int maxProfit_Tabulation(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        for (int index = n - 1; index >= 0; index--)
        {
            for (int canBuy = 0; canBuy <= 1; canBuy++)
            {
                int profit = 0;
                if (canBuy)
                {
                    int buy = -prices[index] + dp[index + 1][false];
                    int notBuy = dp[index + 1][true];
                    profit = max(buy, notBuy);
                }
                else
                {
                    int sell = prices[index] + dp[index + 1][true];
                    int notSell = dp[index + 1][false];
                    profit = max(sell, notSell);
                }
                dp[index][canBuy] = profit;
            }
        }
        return dp[0][1];
    }
    int maxProfit_SpaceOptimised(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        vector<int> curr(2, 0);
        vector<int> next(2, 0);
        for (int index = n - 1; index >= 0; index--)
        {
            for (int canBuy = 0; canBuy <= 1; canBuy++)
            {
                int profit = 0;
                if (canBuy)
                {
                    int buy = -prices[index] + next[false];
                    int notBuy = next[true];
                    profit = max(buy, notBuy);
                }
                else
                {
                    int sell = prices[index] + next[true];
                    int notSell = next[false];
                    profit = max(sell, notSell);
                }
                curr[canBuy] = profit;
            }
            next = curr;
        }
        return curr[1];
    }
};