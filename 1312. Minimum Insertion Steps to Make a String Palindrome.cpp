class Solution
{
public:
    /*
        Approach : Based on Oberservation ->
            -> To check for palindrome (We check LCS of reverse of string with string);
            -> Number of insertions will be equal to non-common(unique) characters in both strings(original string and reversed string.) || number of characters that are not in LCS.
    */

    // Recursive Approach to Solve LCS
    int longestCommonSub(int index1, int index2, string &s1, string &s2)
    {
        if (index1 >= s1.size() || index2 >= s2.size())
            return 0;
        if (s1[index1] == s2[index2])
        {
            return 1 + longestCommonSub(index1 + 1, index2 + 1, s1, s2);
        }
        return max(longestCommonSub(index1 + 1, index2, s1, s2), longestCommonSub(index1, index2 + 1, s1, s2));
    }
    int minInsertions(string s)
    {
        string a = s;
        reverse(s.begin(), s.end());
        int size = longestCommonSub(0, 0, a, s);
        return s.size() - size;
    }
    // Adding memoization
    int dp[501][501];
    int longestCommonSub(int index1, int index2, string &s1, string &s2)
    {
        if (index1 >= s1.size() || index2 >= s2.size())
            return 0;
        if (dp[index1][index2] != -1)
            return dp[index1][index2];
        if (s1[index1] == s2[index2])
        {
            return dp[index1][index2] = 1 + longestCommonSub(index1 + 1, index2 + 1, s1, s2);
        }
        return dp[index1][index2] = max(longestCommonSub(index1 + 1, index2, s1, s2), longestCommonSub(index1, index2 + 1, s1, s2));
    }

    // Bottom Up DP
    int minInsertions(string s)
    {
        int dp[501][501] = {0};
        string s1 = s;
        reverse(s.begin(), s.end());
        string s2 = s;
        for (int index1 = s1.size() - 1; index1 >= 0; index1--)
        {
            for (int index2 = s2.size() - 1; index2 >= 0; index2--)
            {
                if (index1 >= s1.size() || index2 >= s2.size())
                {
                    dp[index1][index2] = 0;
                    continue;
                }
                if (s1[index1] == s2[index2])
                {
                    dp[index1][index2] = 1 + dp[index1 + 1][index2 + 1];
                    continue;
                }
                dp[index1][index2] = max(dp[index1][index2 + 1], dp[index1 + 1][index2]);
            }
        }
        return s.size() - dp[0][0];
    }
};