class Solution {
public:
    int minPathSum_Memoization(vector<vector<int>>& grid,int x,int y,vector<vector<int>> &dp){
        if(x==grid.size()-1 && y==grid[0].size()-1){
            return grid[x][y];
        }
        if(dp[x][y]!=-1)return dp[x][y];
        int row=INT_MAX;
        int col=INT_MAX;
        if(y+1<grid[0].size()){
            row=helper(grid,x,y+1,dp);
        }
        if(x+1<grid.size()){
            col=helper(grid,x+1,y,dp);
        }
        return dp[x][y]=grid[x][y]+min(row,col);
    }
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size()+1,vector<int>(grid[0].size()+1,-1));
        return minPathSum_Memoization(grid,0,0,dp);
    }
    int minPathSum_Tabulation(vector<vector<int>>& grid) {
        int xMax=grid.size()-1;
        int yMax=grid[0].size()-1;
        vector<vector<int>> dp(xMax+2,vector<int>(yMax+2,0));
        dp[xMax][yMax]=grid[xMax][yMax];
        for(int x=xMax;x>=0;x--){
            for(int y=yMax;y>=0;y--){
                if (x==xMax && y==yMax) continue;
                int right =INT_MAX;
                int down =INT_MAX;
                if(y+1 <= yMax){
                    right = dp[x][y + 1];
                }
                if(x+1 <= xMax){
                    down = dp[x + 1][y];
                }
                dp[x][y] = grid[x][y] + min(down, right); 
            }
        }
        return dp[0][0];
    }
};


/*

-----Recursive Approach-----

1. Start from 0,0 till n-1,m-1.
2. Return Value of Current Postion + Minimum Value (After going Down || After going Right).
3. Reached Till End Return Last Positon(n-1,m-1).

-----Tabulation Based Approach-----

1. Base condition DP[xMax][yMax] will store Same value as Grid[xMax][yMax].
2. Calculate both condition i.e. right or down
3. Store DP[X][Y] with grid[x][y] + minimum of right and down ( means which would you have choosen to come down ).
4. After reaching Top DP[0][0] (Means You have Come all through way Down -> Up with minimum possible cost/path).
5.Return Top DP[0][0].

*/



/*

Extra Notes :-

* If we have DP problem we try to reduce it to minimum changing variables(In Recursive function calls...)
* We can also choose to make changes in original given grid;

*/