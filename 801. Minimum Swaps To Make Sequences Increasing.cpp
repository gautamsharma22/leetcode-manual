class Solution
{
public:
    int minSwapRec(vector<int> &nums1, vector<int> &nums2, int index, bool already_swapped)
    {
        if (index == nums1.size())
            return 0;
        int prev1 = nums1[index - 1];
        int prev2 = nums2[index - 1];
        int ans = nums1.size();
        if (already_swapped)
        {
            swap(prev1, prev2);
        }
        // if its increasing then no need to swap
        if (nums1[index] > prev1 && nums2[index] > prev2)
            ans = min(ans, minSwapRec(nums1, nums2, index + 1, 0));
        // if its non increasing then we need to swap
        if (nums1[index] > prev2 && nums2[index] > prev1)
        { // Here we are checking if after swafter swapping will it make strictly increasing  then Only swap...
            ans = min(ans, 1 + minSwapRec(nums1, nums2, index + 1, 1));
        }
        return ans;
    }
    int minSwapMem(vector<int> &nums1, vector<int> &nums2, int index, bool already_swapped, vector<vector<int>> &dp)
    {
        if (index == nums1.size())
            return 0;
        if (dp[index][already_swapped] != -1)
            return dp[index][already_swapped];
        int prev1 = nums1[index - 1];
        int prev2 = nums2[index - 1];
        int ans = nums1.size();
        if (already_swapped)
        {
            swap(prev1, prev2);
        }
        // if its increasing then no need to swap
        if (nums1[index] > prev1 && nums2[index] > prev2)
            ans = min(ans, minSwapMem(nums1, nums2, index + 1, 0, dp));
        // if its non increasing then we need to swap
        if (nums1[index] > prev2 && nums2[index] > prev1)
        { // Here we are checking if after swafter swapping will it make strictly increasing order then swap...
            ans = min(ans, 1 + minSwapMem(nums1, nums2, index + 1, 1, dp));
        }
        return dp[index][already_swapped] = ans;
    }
    int minSwapTab(vector<int> &nums1, vector<int> &nums2)
    {
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);
        int n = nums1.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        for (int index = n - 1; index >= 1; index--)
        {
            for (int already_swapped = 1; already_swapped >= 0; already_swapped--)
            {
                int prev1 = nums1[index - 1];
                int prev2 = nums2[index - 1];
                int ans = nums1.size();
                if (already_swapped)
                {
                    swap(prev1, prev2);
                }
                if (nums1[index] > prev1 && nums2[index] > prev2)
                    ans = dp[index + 1][0];
                if (nums1[index] > prev2 && nums2[index] > prev1)
                {
                    ans = min(ans, 1 + dp[index + 1][1]);
                }
                dp[index][already_swapped] = ans;
            }
        }
        return dp[1][0];
    }
    int minSwapSpace_Optimised(vector<int> &nums1, vector<int> &nums2)
    {
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);
        int n = nums1.size();
        int swap = 0;
        int noswap = 0;
        int currswap = 0;
        int currnoswap = 0;
        for (int index = n - 1; index >= 1; index--)
        {
            for (int already_swapped = 1; already_swapped >= 0; already_swapped--)
            {
                int prev1 = nums1[index - 1];
                int prev2 = nums2[index - 1];
                int ans = nums1.size();
                if (already_swapped)
                {
                    int temp = prev1;
                    prev1 = prev2;
                    prev2 = temp;
                }
                if (nums1[index] > prev1 && nums2[index] > prev2)
                    ans = noswap;
                if (nums1[index] > prev2 && nums2[index] > prev1)
                {
                    ans = min(ans, 1 + swap);
                }
                if (already_swapped)
                    currswap = ans;
                else
                    currnoswap = ans;
            }
            swap = currswap;
            noswap = currnoswap;
        }
        return min(swap, noswap);
    }
};