class Solution
{
public:
    /*
    Approach ->

    (Tried Recursive Version in Contest and Got TLE)
    Little Bit Optimised Approach.
        * Create a queue to store how far we can reach till now.
        * Starting from position {0,0} so push {0,0} to queue.
        * Mark {0,0} as visited.
        * If maximum possible distance from that cell is out of bounds skip, if its in bound then,Take maximum possible distance from that cell to reach end. (Push the distance of newRow and Col or newCol or row).
        * If any at point row==n-1 and col== m-1 means we've reached end.
        * Return Steps.

    */
    int minimumVisitedCells(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        visited[0][0] = true;
        queue<pair<int, int>> q;
        q.push({0, 0});
        int steps = 0;
        while (!q.empty())
        {
            int size = q.size();
            while (size--)
            {
                auto [row, col] = q.front();
                q.pop();
                if (row == n - 1 && col == m - 1)
                {
                    return steps + 1;
                }
                if (grid[row][col] == 0)
                    continue;
                for (int newRow = grid[row][col] + row; newRow >= row + 1; newRow--)
                {
                    if (newRow >= n or visited[newRow][col])
                        continue;
                    q.push({newRow, col});
                    visited[newRow][col] = 1;
                }
                for (int newCol = grid[row][col] + col; newCol >= col + 1; newCol--)
                {
                    if (newCol >= m or visited[row][newCol])
                        continue;
                    q.push({row, newCol});
                    visited[row][newCol] = 1;
                }
            }
            steps++;
        }
        return -1;
    }
};