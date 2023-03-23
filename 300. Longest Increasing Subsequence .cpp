class Solution
{
public:
    // Recursion based solution on intuition of take or not take.
    int helper(vector<int> &nums, int index, int prev)
    {
        if (index == nums.size())
        {
            return 0;
        }
        int include = 0;
        if (prev == -1 || nums[prev] < nums[index])
        {
            include = 1 + helper(nums, index + 1, index);
        }
        int exclude = helper(nums, index + 1, prev);
        return max(include, exclude);
    }
    // Recursion + Memoization applied on above solution.
    int helper(vector<int> &nums, int index, int prev, vector<vector<int>> &dp)
    {
        if (index == nums.size())
        {
            return 0;
        }
        if (dp[index][prev + 1] != -1)
            return dp[index][prev + 1];
        int include = 0;
        if (prev == -1 || nums[prev] < nums[index])
        {
            include = 1 + helper(nums, index + 1, index, dp);
        }
        int exclude = helper(nums, index + 1, prev, dp);
        return dp[index][prev + 1] = max(include, exclude);
    }
    // Tabulation of above code intuition reamins same;
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int index = n - 1; index >= 0; index--)
        {
            for (int prev = index - 1; prev >= -1; prev--)
            {
                int include = 0;
                if (prev == -1 || nums[index] > nums[prev])
                {
                    include = 1 + dp[index + 1][index + 1];
                }
                int exclude = dp[index + 1][prev + 1];
                dp[index][prev + 1] = max(include, exclude);
            }
        }
        return dp[0][0];
    }
    // sapace optimisation of above code.
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> curr_(n + 1, 0);
        vector<int> next_(n + 1, 0);
        for (int index = n - 1; index >= 0; index--)
        {
            for (int prev = index - 1; prev >= -1; prev--)
            {
                int include = 0;
                if (prev == -1 || nums[index] > nums[prev])
                {
                    include = 1 + next_[index + 1];
                }
                int exclude = next_[prev + 1];
                curr_[prev + 1] = max(include, exclude);
            }
            next_ = curr_;
        }
        return next_[0];
    }
    // New approach (Applying Binary Search with DP ) (It counts lenght only).
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans;
        ans.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > ans.back())
            {
                ans.push_back(nums[i]);
            }
            else
            {
                vector<int>::iterator lower;
                lower = lower_bound(ans.begin(), ans.end(), nums[i]); // Replace the strictly lower element with current element
                int index = lower - ans.begin();
                ans[index] = nums[i];
            }
        }
        return ans.size();
    }
};
