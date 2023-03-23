class Solution
{
public:
    int helperRec(int index, int size, vector<int> &slices, int total_eat)
    {
        if (index > size || total_eat <= 0)
        {
            return 0;
        }
        int eat = slices[index] + helperRec(index + 2, size, slices, total_eat - 1);
        int not_eat = 0 + helperRec(index + 1, size, slices, total_eat);
        return max(eat, not_eat);
    }
    int helperMem(int index, int size, vector<int> &slices, int total_eat, vector<vector<int>> &dp)
    {
        if (index > size || total_eat <= 0)
        {
            return 0;
        }
        if (dp[index][total_eat] != -1)
            return dp[index][total_eat];
        int eat = slices[index] + helperMem(index + 2, size, slices, total_eat - 1, dp);
        int not_eat = 0 + helperMem(index + 1, size, slices, total_eat, dp);
        return dp[index][total_eat] = max(eat, not_eat);
    }
    int maxSizeSlices(vector<int> &slices)
    {
        int n = slices.size();
        int total_eat = n / 3;
        vector<vector<int>> dp(n + 1, vector<int>(total_eat + 1, -1));
        int a = helperMem(0, n - 2, slices, total_eat, dp);
        vector<vector<int>> dp1(n + 1, vector<int>(total_eat + 1, -1));
        int b = helperMem(1, n - 1, slices, total_eat, dp1);
        return max(a, b);
    }
    int helperTab(int in, int size, vector<int> &slices)
    {
        int n = slices.size();
        int total = n / 3;
        vector<vector<int>> dp(n + 2, vector<int>(total + 2, 0));
        for (int index = size; index >= in; index--)
        {
            for (int total_eat = 1; total_eat <= total; total_eat++)
            {
                int eat = slices[index] + dp[index + 2][total_eat - 1];
                int not_eat = 0 + dp[index + 1][total_eat];
                dp[index][total_eat] = max(eat, not_eat);
            }
        }
        return dp[in][total];
    }
    int maxSizeSlices(vector<int> &slices)
    {
        int n = slices.size();
        int total_eat = n / 3;
        int a = helperTab(0, n - 2, slices);
        int b = helperTab(1, n - 1, slices);
        return max(a, b);
    }
    int helperTab_Space_Optim(int in, int size, vector<int> &slices)
    {
        int n = slices.size();
        int total = n / 3;
        vector<int> prev(total + 2, 0);
        vector<int> curr(total + 2, 0);
        vector<int> next(total + 2, 0);
        for (int index = size; index >= in; index--)
        {
            for (int total_eat = 1; total_eat <= total; total_eat++)
            {
                int eat = slices[index] + next[total_eat - 1];
                int not_eat = 0 + curr[total_eat];
                prev[total_eat] = max(eat, not_eat);
            }
            next = curr;
            curr = prev;
        }
        return prev[total];
    }
    int maxSizeSlices(vector<int> &slices)
    {
        int n = slices.size();
        int total_eat = n / 3;
        int a = helperTab_Space_Optim(0, n - 2, slices);
        int b = helperTab_Space_Optim(1, n - 1, slices);
        return max(a, b);
    }
};