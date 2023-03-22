class Solution
{
public:
    int helper(vector<int> &obstacles, int currentPos, int currLane)
    {
        int n = obstacles.size() - 1;
        if (currentPos == n)
            return 0;
        if (currLane != obstacles[currentPos + 1])
        {
            return helper(obstacles, currentPos + 1, currLane);
        }
        else
        {
            int ans = INT_MAX;
            for (int i = 1; i <= 3; i++)
            {
                if (currLane != i && i != obstacles[currentPos])
                {
                    ans = min(ans, 1 + helper(obstacles, currentPos + 1, i));
                }
            }
            return ans;
        }
    }
    int helperMem(vector<int> &obstacles, int currLane, int currentPos, vector<vector<int>> &dp)
    {
        int n = obstacles.size() - 1;
        if (currentPos == n)
            return 0;
        if (dp[currLane][currentPos] != -1)
            return dp[currLane][currentPos];
        if (currLane != obstacles[currentPos + 1])
        {
            return dp[currLane][currentPos] = helperMem(obstacles, currLane, currentPos + 1, dp);
        }
        else
        {
            int ans = INT_MAX;
            for (int i = 1; i <= 3; i++)
            {
                if (currLane != i && i != obstacles[currentPos])
                {
                    ans = min(ans, 1 + helperMem(obstacles, i, currentPos + 1, dp));
                }
            }
            return dp[currLane][currentPos] = ans;
        }
    }
    int helperTab(vector<int> &obstacles)
    {
        int n = obstacles.size() - 1;
        vector<vector<int>> dp(4, vector<int>(n + 1, 1e9));
        dp[0][n] = 0;
        dp[1][n] = 0;
        dp[2][n] = 0;
        dp[3][n] = 0;
        for (int currentPos = n - 1; currentPos >= 0; currentPos--)
        {
            for (int currLane = 1; currLane <= 3; currLane++)
            {
                if (currLane != obstacles[currentPos + 1])
                {
                    dp[currLane][currentPos] = dp[currLane][currentPos + 1];
                }
                else
                {
                    int ans = 1e9;
                    for (int i = 1; i <= 3; i++)
                    {
                        if (currLane != i && i != obstacles[currentPos])
                        {
                            ans = min(ans, 1 + dp[i][currentPos + 1]);
                        }
                    }
                    dp[currLane][currentPos] = ans;
                }
            }
        }
        return min(dp[2][0], min(1 + dp[3][0], 1 + dp[1][0]));
    }
    int minSideJumps(vector<int> &obstacles)
    {
        vector<vector<int>> dp(3 + 1, vector<int>(obstacles.size() + 1, -1));
        return helperTab(obstacles);
    }
};