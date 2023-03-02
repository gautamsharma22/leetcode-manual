class Solution {
public:
    bool isSafe(vector<string> &board,int row,int col,int n){
        int x=row;
        int y=col;
        while(y>=0){
            if(board[x][y]=='Q')return false;
            y--;
        }
        x=row;
        y=col;
        while(x< n && y>=0){
            if(board[x][y]=='Q')return false;
            y--;
            x++;
        }
        x=row;
        y=col;
        while(x >=0 && y>=0){
            if(board[x][y]=='Q')return false;
            y--;
            x--;
        }
        return true;
    }
    void helper(vector<vector<string>> &ans,vector<string> board,int col,int n){
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            if(isSafe(board,row,col,n)){
                board[row][col]='Q';
                helper(ans,board,col+1,n);
                board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i = 0; i<n; i++){
            board[i] = s;
        }
        helper(ans,board,0,n);
        return ans;
    }
};