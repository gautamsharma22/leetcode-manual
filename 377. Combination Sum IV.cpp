class Solution
{
public:
    int helper(vector<int> &nums, int target, vector<int> &dp)
    {
        if (target == 0)
            return 1;
        if (target < 0)
            return 0;
        int ans = 0;
        if (dp[target] != -1)
            return dp[target];
        for (auto i : nums)
        {
            ans += helper(nums, target - i, dp);
        }
        return dp[target] = ans;
    }
    int combinationSum4(vector<int> &nums, int target)
    {
        vector<int> dp(target + 1, -1);
        return helper(nums, target, dp);
    }
};