class Solution
{
    /*
    Approach->
            Simple(Traverse Diagonally in matrix and update max prime found in diagonal)
    */
public:
    bool isPrime(int n)
    {
        if (n < 2)
            return false;
        for (int i = 2; i <= sqrt(n); i++)
        {
            if (n % i == 0)
            {
                return false;
            }
        }
        return true;
    }
    int diagonalPrime(vector<vector<int>> &nums)
    {
        int n = nums.size();
        int maxDiag = 0;

        for (int i = 0, j = n - 1; i < n; i++, j--)
        {
            int num = nums[i][i]; // For topleft to Bottom Right.
            if (isPrime(num))
            {
                maxDiag = max(maxDiag, num);
            }
            int num1 = nums[i][j]; // For Bottom left to top Right.
            if (isPrime(num1))
            {
                maxDiag = max(maxDiag, num1);
            }
        }

        return maxDiag;
    }
};
