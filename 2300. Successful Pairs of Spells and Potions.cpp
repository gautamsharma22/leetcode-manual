class Solution
{
public:
    /*
    Approach:

    (Bruteforce) will give TLE cause it will (m*n) time and n is order of 10^5
    1.) Calculate each pair and check if it is a valid success or not.
    2.) Update pairs array also.
    (Optimization with binary search)

    1.) Sort the Potions Array
    2.) For each Spell Apply a Binary Search on potions array and find index of lowest possible element that matches the succcess.
    3.) Calculate toal elements by Subtracting index of lowest possible element with size of potions becuase all the element now will be greater than succcess.
    4.)Update the pairs Array also.


     */
    vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success)
    {
        int n = spells.size();
        int m = potions.size();
        vector<int> pairs(n, 0);
        sort(potions.begin(), potions.end());
        for (int i = 0; i < n; i++)
        {
            int count = 0;
            int left = 0;
            int right = m - 1;
            while (left <= right)
            {
                int mid = left + (right - left) / 2;
                long long product = (long long)potions[mid] * spells[i];
                if (product >= success)
                {
                    count = m - mid;
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
            pairs[i] = count;
        }
        return pairs;
    }
};