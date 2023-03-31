class NumMatrix
{
public:
    /*
    Approach :
    Similar problem as Range Sum Query 1D
    Just Used a loop to increment row.
    */
    vector<vector<int>> prefix;
    NumMatrix(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        prefix = vector<vector<int>>(n, vector<int>(m, 0));
        for (int row = 0; row < matrix.size(); row++)
        {
            int ans = 0;
            for (int col = 0; col < matrix[0].size(); col++)
            {
                ans += matrix[row][col];
                prefix[row][col] = ans;
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        int sum = 0;
        for (int row = row1; row <= row2; row++)
        {
            sum += prefix[row][col2] - (col1 ? prefix[row][col1 - 1] : 0);
        }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */