class Solution
{
    /*
        Approach: (Not intuitive Solved by watching Youtube sol)
            Constraints are strict so can't use n^2.
            Using O(nLogn) sol using binary search + Traversal (Monotonic Stack Approach)
        States = LongestSequence[i]=x {Length of sequence = i+1 && greates value upto that sequence = x}
    */
public:
    // vector<int> longestObstacleCourseAtEachPosition(vector<int> &obstacles)
    // {
    //     int n = obstacles.size();
    //     vector<int> longestSequence(n, 1);
    //     for (int i = 0; i < n; i++)
    //     {
    //         for (int j = 0; j < i; j++)
    //         {
    //             if (obstacles[j] <= obstacles[i])
    //             {
    //                 longestSequence[i] = max(longestSequence[i], longestSequence[j] + 1);
    //             }
    //         }
    //     }
    //     return longestSequence;
    // }
    int search(vector<int> &arr, int val)
    {
        int left = 0;
        int right = arr.size();
        while (left < right)
        {
            int mid = (left + right) / 2;
            if (arr[mid] <= val)
            {
                left = mid + 1;
            }
            if (arr[mid] > val)
            {
                right = mid;
            }
        }
        return left;
    }
    vector<int> longestObstacleCourseAtEachPosition(vector<int> &obstacles)
    {
        int n = obstacles.size();
        vector<int> longestSequence;
        vector<int> ans(n, 1);
        for (int i = 0; i < n; i++)
        {
            int pos = search(longestSequence, obstacles[i]);
            if (pos == longestSequence.size())
            {
                longestSequence.push_back(obstacles[i]);
            }
            else
            {
                longestSequence[pos] = obstacles[i];
            }
            ans[i] = pos + 1;
        }
        return ans;
    }
};