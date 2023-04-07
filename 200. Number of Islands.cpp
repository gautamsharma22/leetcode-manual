class Solution
{
public:
    /*
    Approach : (Very same to another islands problem)
    * Traverse through Grid if any land found (mark them as visited and other connected lans to them viited too.)
    (In this case instead of marking viisted we mark them as water)
    * Return total number of counts.
    */
    void dfs(int i, int j, vector<vector<char>> &grid)
    {
        if ((i >= 0 && i < grid.size()) && (j >= 0 && j < grid[0].size()))
        {
            if (grid[i][j] == '1')
            {
                grid[i][j] = '0';
                dfs(i + 1, j, grid);
                dfs(i - 1, j, grid);
                dfs(i, j + 1, grid);
                dfs(i, j - 1, grid);
            }
        }
    }
    int numIslands(vector<vector<char>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == '1')
                {
                    count++;
                    dfs(i, j, grid);
                }
            }
        }
        return count;
    }
};