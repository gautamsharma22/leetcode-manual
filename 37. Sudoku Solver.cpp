class Solution {
public:
    bool issafe(vector<vector<char>>& board,int row,int col,char data){
        for(int i=0;i<board.size();i++){
            if(board[i][col]==data)return false;
            if(board[row][i]==data)return false;
            if (board [3* (row/3) + i/3] [3* (col/3) + i%3] == data)return false;
        }
        return true;
    }
    bool helper(vector<vector<char>>& board,int i,int j){
        if(i==9)return true;
        if(j==9) return helper(board, i+1, 0);
        if(board[i][j]!='.')return helper(board, i, j+1);
        for(char ch='1';ch<='9';ch++){
            if(issafe(board,i,j,ch)){
                board[i][j]=ch;
                if(helper(board,i,j+1))return true;
                board[i][j] = '.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        helper(board,0,0);
        return;
    }
};