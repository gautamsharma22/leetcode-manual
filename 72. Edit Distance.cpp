class Solution
{
public:
    int minDistance_Memoization(string s1, string s2, int in1, int in2, vector<vector<int>> &dp)
    {
        if (in1 >= s1.size())
        {
            return s2.size() - in2; // You have to delete the remaining string, get remaining string count by size of 2nd string - currposition of iterator(in2)
        }
        if (in2 >= s2.size())
        {
            return s1.size() - in1; // we have to delete the remaining string, get remaining string count by size of 1st string  - currposition of iterator(in1)
        }
        if (dp[in1][in2] != -1)
            return dp[in1][in2];
        int ans = 0;

        if (s1[in1] == s2[in2])
        {
            return dp[in1][in2] = helper(s1, s2, in1 + 1, in2 + 1, dp); // If they are equal
        }
        else
        {
            // Insert a character
            int insert = 1 + helper(s1, s2, in1, in2 + 1, dp);
            // Delete a character
            int delet = 1 + helper(s1, s2, in1 + 1, in2, dp);
            // Replace a character
            int replace = 1 + helper(s1, s2, in1 + 1, in2 + 1, dp);
            ans = min(insert, min(delet, replace));
        }
        return dp[in1][in2] = ans;
    }
    int minDistance_Tabulation(string word1, string word2)
    {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
        for (int in2 = 0; in2 < m; in2++)
        {
            dp[word1.size()][in2] = word2.size() - in2;
        }
        for (int in1 = 0; in1 < n; in1++)
        {
            dp[in1][word2.size()] = word1.size() - in1;
        }
        for (int in1 = n - 1; in1 >= 0; in1--)
        {
            for (int in2 = m - 1; in2 >= 0; in2--)
            {
                int ans = 0;
                if (word1[in1] == word2[in2])
                {
                    ans = dp[in1 + 1][in2 + 1];
                }
                else
                {
                    int insert = 1 + dp[in1][in2 + 1];
                    int delet = 1 + dp[in1 + 1][in2];
                    int replace = 1 + dp[in1 + 1][in2 + 1];
                    ans = min(insert, min(delet, replace));
                }
                dp[in1][in2] = ans;
            }
        }
        return dp[0][0];
    }
    int minDistance_SpaceOptimised(string word1, string word2)
    {
        int n = word1.size();
        int m = word2.size();
        if (n == 0)
            return m;
        if (m == 0)
            return n;
        vector<int> curr(word2.size() + 1, 0);
        vector<int> next(word2.size() + 1, 0);
        for (int in2 = 0; in2 < m; in2++)
        {
            next[in2] = word2.size() - in2;
        }
        for (int in1 = n - 1; in1 >= 0; in1--)
        {
            for (int in2 = m - 1; in2 >= 0; in2--)
            {
                curr[word2.size()] = word1.size() - in1;
                int ans = 0;
                if (word1[in1] == word2[in2])
                {
                    ans = next[in2 + 1];
                }
                else
                {
                    int insert = 1 + curr[in2 + 1];
                    int delet = 1 + next[in2];
                    int replace = 1 + next[in2 + 1];
                    ans = min(insert, min(delet, replace));
                }
                curr[in2] = ans;
            }
            next = curr;
        }
        return curr[0];
    }
};