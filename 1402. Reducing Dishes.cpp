class Solution
{
public:
    int maxSatisfactionMem(vector<int> &satisfaction, int index, int time, vector<vector<int>> &dp)
    {
        if (index == satisfaction.size())
            return 0;
        if (dp[index][time] != -1)
            return dp[index][time];
        int include = satisfaction[index] * (time + 1) + maxSatisfactionMem(satisfaction, index + 1, time + 1, dp);
        int exclude = 0 + maxSatisfactionMem(satisfaction, index + 1, time, dp);
        return dp[index][time] = max(include, exclude);
    }
    int maxSatisfactionTab(vector<int> &satisfaction)
    {
        sort(satisfaction.begin(), satisfaction.end());
        int n = satisfaction.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int index = n - 1; index >= 0; index--)
        {
            for (int time = index; time >= 0; time--)
            {
                int include = satisfaction[index] * (time + 1) + dp[index + 1][time + 1];
                int exclude = 0 + dp[index + 1][time];
                dp[index][time] = max(include, exclude);
            }
        }
        return dp[0][0];
    }
    int maxSatisfaction_Space_Optimized(vector<int> &satisfaction)
    {
        sort(satisfaction.begin(), satisfaction.end());
        int n = satisfaction.size();
        vector<int> current(n + 1, 0);
        vector<int> next(n + 1, 0);
        for (int index = n - 1; index >= 0; index--)
        {
            for (int time = index; time >= 0; time--)
            {
                int include = satisfaction[index] * (time + 1) + next[time + 1];
                int exclude = 0 + next[time];
                current[time] = max(include, exclude);
            }
            next = current;
        }
        return current[0];
    }
    int maxSatisfaction(vector<int> &satisfaction)
    {
        sort(satisfaction.begin(), satisfaction.end());
        vector<vector<int>> dp(satisfaction.size(), vector<int>(satisfaction.size(), -1));
        return maxSatisfactionMem(satisfaction, 0, 0, dp);
    }
};