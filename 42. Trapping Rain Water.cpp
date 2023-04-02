class Solution
{
public:
    /*
    Approach :

    1) Create two arrays left and right. Left will contain maximum boundary from left till current position and Right will contain maximum boundary from right till current position.
    2) For Calculating trapped rain water at each index - take minimum of left and right and subtract the current height.
    3) Store the calculated sum for each index.
    */
    int trap(vector<int> &height)
    {
        int n = height.size();
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        left[0] = height[0];
        for (int i = 1; i < n; i++)
        {
            left[i] = max(height[i], left[i - 1]);
        }
        right[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            right[i] = max(height[i], right[i + 1]);
        }
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            int totalTrappedWater = min(left[i], right[i]);
            int holdWater = totalTrappedWater - height[i];
            sum += holdWater;
        }
        return sum;
    }
};