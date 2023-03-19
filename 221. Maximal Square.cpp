class Solution
{
public:
    int helper(vector<vector<char>> &matrix, int i, int j, int &maximum)
    {
        if (i >= matrix.size() || j >= matrix[0].size())
            return 0;
        int right = helper(matrix, i, j + 1, maximum);
        int diag = helper(matrix, i + 1, j + 1, maximum);
        int bottom = helper(matrix, i + 1, j, maximum);
        if (matrix[i][j] == '1')
        {
            int ans = 1 + min(right, min(diag, bottom));
            maximum = max(ans, maximum);
            return ans;
        }
        else
        {
            return 0;
        }
    }
    int helperMem(vector<vector<char>> &matrix, int i, int j, int &maximum, vector<vector<int>> &dp)
    {
        if (i >= matrix.size() || j >= matrix[0].size())
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int right = helperMem(matrix, i, j + 1, maximum, dp);
        int diag = helperMem(matrix, i + 1, j + 1, maximum, dp);
        int bottom = helperMem(matrix, i + 1, j, maximum, dp);
        if (matrix[i][j] == '1')
        {
            int ans = 1 + min(right, min(diag, bottom)); // Store maximum Number of 1's Found
            maximum = max(ans, maximum);
            dp[i][j] = ans;
            return dp[i][j];
        }
        else
        {
            return dp[i][j] = 0;
        }
    }
    int helperTab(vector<vector<char>> &matrix)
    {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int maximum = 0;
        vector<vector<int>> dp(rows + 1, vector<int>(cols + 1, 0));
        for (int i = rows - 1; i >= 0; i--)
        {
            for (int j = cols - 1; j >= 0; j--)
            {
                int right = dp[i][j + 1];
                int diag = dp[i + 1][j + 1];
                int bottom = dp[i + 1][j];
                if (matrix[i][j] == '1')
                {
                    int ans = 1 + min(right, min(diag, bottom));
                    maximum = max(ans, maximum);
                    dp[i][j] = ans;
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
        }
        return maximum * maximum;
    }
    int maximalSquare(vector<vector<char>> &matrix)
    {
        int maximum = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        helperMem(matrix, 0, 0, maximum, dp);
        return maximum * maximum;
    }
};