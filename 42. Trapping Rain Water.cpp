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

    /*
        Approach :
        This approach is based on two pointers and instead of calculating prefix sum array array and postfix sum we reduce it to two variables say leftMax and rightMax.

        1) Initialize maxLeft,maxRight,left,right.(We will start from starting index+1 and go to ending index-1 because boundary values cant store any water.)
        2) Check minimum of leftMax and rightMax, if left is minimum ->
        2) Calculate the maxLeft-heightLeft (Empty Space).
        3) Store value in total (trappedWater).
        4) Update max left if greater value found.
        5) Update Left+1.
        6) Do same thing for right also.

        Reason this approach works because at starting we are checking min of maxLeft and maxRight and taking whichever is minimum by this we ensure that the at any position the maximum value any index can store should be min of (maxRight,maxLeft). the same thing used here.

        Suppose in maxLeft=2 maxRight=3; In any case boundary between any two point comes out 10 so if we are moving from left we would only store 2(Greater than 2 will cause spilling of water).
    */
    int trapSpaceOptimised(vector<int> &height)
    {
        int n = height.size();
        int maxLeft = height[0];
        int maxRight = height[n - 1];
        int left = 1;
        int right = n - 2;
        int trappedWater = 0;
        while (left <= right)
        {
            if (maxLeft <= maxRight)
            {
                int x = maxLeft - height[left];
                if (x > 0)
                    trappedWater += x;
                if (height[left] > maxLeft)
                    maxLeft = height[left];
                left++;
            }
            else
            {
                int x = maxRight - height[right];
                if (x > 0)
                    trappedWater += x;
                if (height[right] > maxRight)
                    maxRight = height[right];
                right--;
            }
        }
        return trappedWater;
    }
};