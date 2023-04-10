class Solution
{
public:
    /*
    Approach ->
        -> Calculating all possible differcences until we find one. -> TC(10^5 * N) Obviously TLE.
        * Sort the array because minimum diff can be found at any element by nums[i-1]-nums[i] or nums[i+1]-nums[i].
        * Start from minimum differnce 0 to max Difference possible in array (nums[n-1]-nums[0]).
        * If pairs found with same distance reduce pairs by one and continue the search till we get pair==0.
        * Anytime pair ==0 return diff (It'll be minimum because it's constantly increasing)

        ->Optimization using Binary Search
        * Approach will be same instead of calculating difference from 0 to maxDifference we can apply Binary search to reduce Time Complexity.
        * Apply Binary Search and store the ans .
        * At end of while return ans.


    */
    // Bruteforce approach(Will give TLE)
    bool isPossible(vector<int> &nums, int diff, int totalPair)
    {
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i + 1] - nums[i] <= diff)
            {
                totalPair--;
                i++; // Because one index can be paired with one pair only.
            }
            if (totalPair == 0)
                return true;
        }
        return false;
    }
    int minimizeMax(vector<int> &nums, int p)
    {
        if (p == 0)
            return p;
        sort(nums.begin(), nums.end());
        // Find all pairs starting from minimum difference till maximum difference
        int n = nums.size();
        int a = 0;
        int maxDiff = nums[n - 1] - nums[0];
        while (a <= maxDiff)
        {
            if (isPossible(nums, a, p))
                return a;
            a++;
        }
        return -1;
    }
    bool isPossible(vector<int> &nums, int diff, int totalPair)
    {
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i + 1] - nums[i] <= diff)
            {
                totalPair--;
                i++;
            }
            if (totalPair == 0)
                return true;
        }
        return false;
    }
    int minimizeMax(vector<int> &nums, int p)
    {
        if (p == 0)
            return p;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int left = 0;
        int right = nums[n - 1] - nums[0];
        int ans = 0;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (isPossible(nums, mid, p))
            {
                ans = mid; // It may or may not be ans so we store it and continue the iteration.
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return ans;
    }
};