class Solution
{
public:
    /*
        Similar with Leetcode 1020.
        Approach:
            * Traverse throgh all boundary elements first and mark them and their connected plots to 1s.(Because boundary elements are not counted as closed enclaves).
            * Next Travers through remaining grid and count number of remaning islands (That are closed.)
            * To keep a check on -> only connected islands are counted only one time we run dfs on them to ones we visit them and mark them 1.
        */
    void dfs(int i, int j, vector<vector<int>> &grid)
    {
        if ((i >= 0 && i < grid.size()) && (j >= 0 && j < grid[0].size()))
        {
            if (grid[i][j] == 0)
            {
                grid[i][j] = 1;
                dfs(i + 1, j, grid);
                dfs(i - 1, j, grid);
                dfs(i, j + 1, grid);
                dfs(i, j - 1, grid);
            }
        }
    }
    int closedIsland(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i * j == 0 || i == n - 1 || j == m - 1)
                { // Convert boundary land to water and its connected plot too.
                    if (grid[i][j] == 0)
                    {
                        dfs(i, j, grid);
                    }
                }
            }
        }
        // Traverse through remaining grid and count remaining lands
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 0)
                {
                    count++;
                    dfs(i, j, grid); // Count connected pieces of land as 1 land
                }
            }
        }
        return count;
    }
};