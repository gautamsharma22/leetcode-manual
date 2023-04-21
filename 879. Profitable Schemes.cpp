class Solution
{
public:
    /*
        Approach (Based on Take and Not Take):

        * If we are commiting any crime then reduce the number of people and reduce total profit required.
        * If we get to zero means this was a valid group so increase the count by 1;
        * If not then it was invalid (Don't increase count);
        * Return the answer.

    */
    // Recursion (Gives TLE)
    const int MOD = 1e9 + 7;
    int Recursion(int index, int n, int minProfit, vector<int> &group, vector<int> &profit)
    {
        if (n < 0)
            return 0;
        if (index >= group.size())
        {
            return (minProfit <= 0);
        }
        int commitCrime = 0;
        int notCommit = 0;
        if (group[index] <= n)
            commitCrime += Recursion(index + 1, n - group[index], minProfit - profit[index], group, profit);
        notCommit += Recursion(index + 1, n, minProfit, group, profit);
        return (commitCrime + notCommit) % MOD;
    }
    int profitableSchemes(int n, int minProfit, vector<int> &group, vector<int> &profit)
    {
        return Recursion(0, n, minProfit, group, profit);
    }

    // Recursion With Memoization and Boundary Checks (Accepted)
    int dp[101][101][101];
    int Memoization(int index, int n, int minProfit, vector<int> &group, vector<int> &profit)
    {
        if (n < 0)
            return 0;
        if (index >= group.size())
        {
            return (minProfit <= 0);
        }
        if (dp[index][n][minProfit] != -1)
        {
            return dp[index][n][minProfit];
        }
        int commitCrime = 0;
        int notCommit = 0;
        if (group[index] <= n)
        {
            commitCrime += Memoization(index + 1, n - group[index], minProfit - profit[index] > 0 ? minProfit - profit[index] : 0, group, profit); // If current profit - profit we'll make after this crime is less than zero, then we'll set it to 0(To avoid negative index error.)
        }
        notCommit += Memoization(index + 1, n, minProfit, group, profit);
        return dp[index][n][minProfit] = (commitCrime + notCommit) % MOD;
    }
    int profitableSchemes(int n, int minProfit, vector<int> &group, vector<int> &profit)
    {
        memset(dp, -1, sizeof(dp));
        return Memoization(0, n, minProfit, group, profit);
    }

    // Bottom Up Solution (Accepted)
    int BottomUpDP(int n_, int minProfit_, vector<int> &group, vector<int> &profit)
    {
        int size = group.size();
        // vector<vector<vector<int>>> dp(size+2,vector<vector<int>>(n_+2,vector<int>(minProfit_+2,0)));
        int dp[101][101][101]; // As per Given test Case this would be efficient.
        for (int index = size; index >= 0; index--)
        {
            for (int n = 0; n <= n_; n++)
            {
                for (int minProfit = 0; minProfit <= minProfit_; minProfit++)
                {
                    int commitCrime = 0;
                    int notCommit = 0;
                    if (index == group.size())
                    {
                        dp[index][n][minProfit] = (minProfit <= 0);
                        continue;
                    }
                    if (group[index] <= n)
                    {
                        if (n - group[index] < 0)
                            commitCrime += 0;
                        else
                            commitCrime += dp[index + 1][n - group[index]][minProfit - profit[index] > 0 ? minProfit - profit[index] : 0];
                    }
                    notCommit += dp[index + 1][n][minProfit];
                    dp[index][n][minProfit] = (commitCrime + notCommit) % MOD;
                }
            }
        }
        /* If we want to print DP table to see how we arrived to solution */
        // for(auto a:dp){
        //     for(auto b:a){
        //         for(auto c:b){
        //             cout<<c<<" ";
        //         }
        //         cout<<endl;
        //     }
        //         cout<<endl;
        // }
        return dp[0][n_][minProfit_];
    }
};