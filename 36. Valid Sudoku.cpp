class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows[9][9]={0};
        int cols[9][9]={0};
        int c[9][9]={0};    // for small 3*3 grid
        int blocks[3][3][9]={0};
        for(int row=0;row<9;row++){
            for(int col=0;col<9;col++){
                if(board[row][col]!='.'){
                    int n=board[row][col]-'1';
                    int x=row / 3 * 3 + col / 3;    // for small 3*3 grid 
                    if( rows[row][n]++ ||
                        cols[col][n]++ ||
                        c[x][n]++ )
                    return false;
                }
            }
        }
        return true;
    }
};
