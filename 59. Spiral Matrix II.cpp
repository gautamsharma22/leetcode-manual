class Solution
{
public:
    /*
        Approach :-
        *) Initialise iterators left,right,top,and bottom.
        *) While simulating in matrix consider each set of moves as steps.
        *) After each set is complete increment or decrement its counter.
    */
    vector<vector<int>> generateMatrix(int n)
    {
        int left = 0;
        int right = n - 1;
        int top = 0;
        int bottom = n - 1;
        int step = 1;
        int count = 1;
        vector<vector<int>> ans(n, vector<int>(n, 0));
        while (left < n && top < n)
        {
            if (step == 1)
            {
                for (int i = left; i <= right; i++)
                {
                    ans[top][i] = count++;
                }
                step = 2;
                top++;
            }
            else if (step == 2)
            {
                for (int i = top; i <= bottom; i++)
                {
                    ans[i][right] = count++;
                }
                step = 3;
                right--;
            }
            else if (step == 3)
            {
                for (int i = right; i >= left; i--)
                {
                    ans[bottom][i] = count++;
                }
                step = 4;
                bottom--;
            }
            else if (step == 4)
            {
                for (int i = bottom; i >= top; i--)
                {
                    ans[i][left] = count++;
                }
                left++;
                step = 1;
            }
        }
        return ans;
    }
};