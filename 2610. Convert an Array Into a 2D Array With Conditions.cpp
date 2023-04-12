class Solution
{
public:
    /*
    Approach ->

        TC-> O(N)
        SC-> O(N)
        * Traverse through array and count of how many time an element appear.
        * An element cannot appear in same row twice, so Traverse the resultant array push the element in array and reduce count by 1.
        * Push the row to ans .
        * At any time our row is 0 means all eleents have been traversed so break the loop.

    */
    vector<vector<int>> findMatrix(vector<int> &nums)
    {
        vector<int> a(201, 0);
        for (int i = 0; i < nums.size(); i++)
        {
            a[nums[i]]++;
        }
        vector<vector<int>> ans;
        while (true)
        {
            vector<int> temp;
            for (int i = 0; i < a.size(); i++)
            {
                if (a[i] > 0)
                {
                    temp.push_back(i);
                    a[i]--;
                }
            }
            if (temp.size() > 0)
                ans.push_back(temp);
            else
                break;
        }
        return ans;
    }
    vector<vector<int>> findMatrix_Optimised(vector<int> &nums)
    {
        int maxCount = INT_MIN;
        int a[201] = {0};
        for (int i = 0; i < nums.size(); i++)
        {
            a[nums[i]]++;
            maxCount = max(a[nums[i]], maxCount);
        }
        vector<vector<int>> ans(maxCount);
        for (int i = 0; i < 201; i++)
        {
            for (int j = 0; j < a[i]; j++)
            {
                ans[j].push_back(i);
            }
        }
        return ans;
    }
};