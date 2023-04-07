class Solution
{
public:
    /*
    Similar with Leetcode 1254.
    Approach:
        * Traverse throgh all boundary elements first and mark them and their connected plots to 0s.(Because boundary elements are not counted as enclaves).
        * Next Travers through remaining grid and count  number of 1 (That are enclaves.)
    */
    void dfs(int i, int j, vector<vector<int>> &grid)
    {
        if ((i >= 0 && i < grid.size()) && (j >= 0 && j < grid[0].size()))
        {
            // It is boundary element and contains 1 so mark it as 0 all other plots connected to this mark them 0 too.
            if (grid[i][j] == 1)
            {
                grid[i][j] = 0;
                dfs(i + 1, j, grid);
                dfs(i - 1, j, grid);
                dfs(i, j + 1, grid);
                dfs(i, j - 1, grid);
            }
        }
        return;
    }
    int numEnclaves(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                // Check boundary of grid.
                if (i * j == 0 || i == n - 1 || j == m - 1)
                {
                    if (grid[i][j] == 1)
                    {
                        dfs(i, j, grid);
                    }
                }
            }
        }
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    count++;
                }
            }
        }
        return count;
    }
};