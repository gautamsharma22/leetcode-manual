// Same as House Robber (House are arranged in circular way if we rob [0] we cant rob [n])
class Solution
{
public:
    int helper(vector<int> &nums, int start, int end)
    {
        int prev1 = 0;
        int prev2 = 0;
        for (int i = start; i < end; i++)
        {
            int include = nums[i] + prev1;
            int exclude = 0 + prev2;
            prev1 = prev2;
            prev2 = max(include, exclude);
        }
        return prev2;
    }
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        if (n == 2)
            return max(nums[0], nums[1]);
        return max(helper(nums, 0, n - 1), helper(nums, 1, n)); // Return Maximum of [0] - [n-1] and [1]-[n]
    }
};