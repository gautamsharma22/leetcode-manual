class Solution
{
public:
    /*
    Approach:-> Two Pointer
        * Bruteforce first Element (Try every element as first Element).
        * Implement two pointer approach for the remaing two elements.
    */
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> ans;
        int n = nums.size();
        int i = 0;
        sort(nums.begin(), nums.end());
        while (i < n)
        {
            int j = i + 1;
            int k = n - 1;
            while (j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0)
                {
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    ans.push_back(temp);
                    j++;
                    k--;
                }
                else if (sum > 0)
                {
                    k--;
                }
                else
                {
                    j++;
                }
            }
            i++;
        }
        return ans;
    }
};
/*

Approach:-> Same as above (We're told that only unique subsets are allowed so increment the pointer until we find different element ).

Lines Marked with this (*) are finding next different element.

*/
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> ans;
        int n = nums.size();
        int start = 0;
        sort(nums.begin(), nums.end());
        while (start < n)
        {
            int mid = start + 1;
            int end = n - 1;
            while (mid < end)
            {
                int sum = nums[start] + nums[mid] + nums[end];
                if (sum == 0)
                {
                    vector<int> temp = {nums[start], nums[mid], nums[end]};
                    ans.push_back(temp);
                    while (mid + 1 < n && nums[mid] == nums[mid + 1])
                        mid++; //*
                    mid++;
                    while (end - 1 >= 0 && nums[end] == nums[end - 1])
                        end--; //*
                    end--;
                }
                else if (sum > 0)
                {
                    while (end - 1 > 0 && nums[end] == nums[end - 1])
                        end--; //*
                    end--;
                }
                else
                {
                    while (mid + 1 < n && nums[mid] == nums[mid + 1])
                        mid++; //*
                    mid++;
                }
            }
            while (start + 1 < n && nums[start] == nums[start + 1])
                start++; //*
            start++;
        }
        return ans;
    }
};

/*
    Bruteforce Approach (Check all possible subsets);
*/

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> ans;
        set<vector<int>> s;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    if (nums[i] + nums[j] + nums[k] == 0)
                    {
                        vector<int> temp = {nums[i], nums[j], nums[k]};
                        sort(temp.begin(), temp.end());
                        if (s.find(temp) == s.end())
                        {
                            ans.push_back(temp);
                            s.insert(temp);
                        }
                    }
                }
            }
        }
        return ans;
    }
};