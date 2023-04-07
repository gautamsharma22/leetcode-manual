class Solution
{
public:
    /*
    Approach:
    * Maximum area is calculated as any land is directly to other land connected (non diagnonaly),Calculate area of current land + Connected land;
    * Store and return the maximum.
    */
    int dfs(int i, int j, vector<vector<int>> &grid)
    {
        if ((i >= 0 && i < grid.size()) && (j >= 0 && j < grid[0].size()))
        {
            if (grid[i][j] == 1)
            {                 // If current area is land check for other cother connected area are they land as well if yes they will return the count of connected lands.
                grid[i][j] = 0; // Also mark them as visited ( here we are converting them to water so next time we'll not visit them. )
                int down = dfs(i + 1, j, grid);
                int up = dfs(i - 1, j, grid);
                int right = dfs(i, j + 1, grid);
                int left = dfs(i, j - 1, grid);
                return 1 + down + left + right + up; // Return the total count.
            }
            else
            {
                return 0;
            }
        }
        return 0;
    }
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    int count = dfs(i, j, grid);
                    ans = max(count, ans);
                }
            }
        }
        return ans;
    }
};
