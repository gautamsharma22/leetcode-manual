//Not optimized but working
class Solution {
public:
    bool isSafe(vector<vector<int>> &board,int row,int col,int n){
        int x=row;
        int y=col;
        while(y>=0){
            if(board[x][y]==1)return false;
            y--;
        }
        x=row;
        y=col;
        while(x< n && y>=0){
            if(board[x][y]==1)return false;
            y--;
            x++;
        }
        x=row;
        y=col;
        while(x >=0 && y>=0){
            if(board[x][y]==1)return false;
            y--;
            x--;
        }
        return true;
    }
    void helper(int &count,vector<vector<int>> board,int col,int n){
        if(col==n){
            count++;
            return;
        }
        for(int row=0;row<n;row++){
            if(isSafe(board,row,col,n)){
                board[row][col]=1;
                helper(count,board,col+1,n);
                board[row][col]=0;
            }
        }
    }
    int totalNQueens(int n) {
        int count=0;
        vector<vector<int>> board(n, vector<int> (n,0));
        helper(count,board,0,n);
        return count;
    }
};