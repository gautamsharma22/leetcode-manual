class Solution
{
public:
    /*
        Approach:-
            * Store each element in set so we can get their row and col in O(1);
            * Create an vector of Row and Column to check completenss of row and column
            * Traverse through array and make their row and column to visted;
            * If any time their row count ==Number of elemnts in that row(m) return the index.
    */
    int firstCompleteIndex(vector<int> &arr, vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();
        unordered_map<int, int> rows;
        unordered_map<int, int> cols;
        vector<int> totalRows(n, 0);
        vector<int> totalCols(m, 0);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                rows[mat[i][j]] = i;
                cols[mat[i][j]] = j;
            }
        }
        for (int i = 0; i < arr.size(); i++)
        {
            int rowIndex = rows[arr[i]];
            int colIndex = cols[arr[i]];
            totalRows[rowIndex]++;
            totalCols[colIndex]++;
            if (totalRows[rowIndex] == m || totalCols[colIndex] == n) // We are checking reverse because to mark a row complete we need m items where m is number of columns.And vice versa.
            {
                return i;
            }
        }
        return -1;
    }
};