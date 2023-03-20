class Solution
{
public:
    bool helper(vector<int> &nums, int index, int target, vector<int> &dp)
    {
        if (target == 0)
            return true;
        if (target < 0)
            return false;
        if (index == nums.size() - 1)
            return nums[index] == target;
        if (dp[target] != -1)
            return dp[target];
        bool include = helper(nums, index + 1, target - nums[index], dp);
        bool exclude = helper(nums, index + 1, target, dp);
        dp[target] = include || exclude;
        return dp[target];
    }
    bool helperTab(vector<int> &nums, int k, int n)
    {
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        for (int i = 0; i <= n; i++)
            dp[i][0] = 1;
        for (int index = n - 1; index >= 0; index--)
        {
            for (int target = 0; target <= k; target++)
            {
                bool include = 0;
                if (target - nums[index] >= 0)
                    include = dp[index + 1][target - nums[index]];
                bool exclude = dp[index + 1][target];
                dp[index][target] = include || exclude;
            }
        }
        return dp[0][k];
    }

    bool canPartition(vector<int> &nums)
    {
        int sum = 0;
        for (auto i : nums)
            sum += i;
        if (sum % 2 != 0)
            return false;
        sum = sum / 2;
        int n = nums.size();
        vector<int> dp(sum + 1, -1);
        // return helper(nums,0,sum,dp);
        return helperTab(nums, sum, n);
    }
    bool canPartition_MemoryOptimized(vector<int> &nums)
    {
        int sum = 0;
        for (auto i : nums)
            sum += i;
        if (sum % 2 != 0)
            return false;
        sum = sum / 2;
        int n = nums.size();
        vector<int> current(sum + 1, 0);
        vector<int> next(sum + 1, 0);
        current[0] = 1;
        next[0] = 1;
        for (int index = n - 1; index >= 0; index--)
        {
            for (int target = 0; target <= sum; target++)
            {
                bool include = 0;
                if (target - nums[index] >= 0)
                    include = next[target - nums[index]];
                bool exclude = next[target];
                current[target] = include || exclude;
            }
            next = current;
        }
        return current[sum];
    }
};