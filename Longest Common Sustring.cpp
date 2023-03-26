#include <bits/stdc++.h>
int lcs_Recursion(string &s1, string &s2, int index1, int index2, int count)
{
    // if index reaches 0 return current count
    if (index1 == 0 || m == 0)
        return l;

    if (s1.at(index1 - 1) == s2.at(index2 - 1))
        count = helper(s1, s2, n - 1, index2 - 1, count + 1);
    // length for new sub-string including s1
    int lnIncludingS1 = helper(s1, s2, index1, index2 - 1, 0);

    // length for new sub-string including s2
    int lnIncludingS2 = helper(s1, s2, index1 - 1, index2, 0);

    // Return the maximum of the current count or string after calculating S1 or S2;
    return max(count, max(lnIncludingS1, lnIncludingS2));
}
int lcs_Tabulation(string &s1, string &s2, int n, int m)
{
    vector<vector<int>> dp(n + 2, vector<int>(m + 2, 0));
    int ans = 0;
    // First row and first column will be initialized with zero;
    for (int index1 = 1; index1 <= n; index1++)
    {
        for (int index2 = 1; index2 <= m; index2++)
        {
            // Comapre previous elements if equal than update current dp[index1][index2]
            if (s1[index1 - 1] == s2[index2 - 1])
            {
                dp[index1][index2] = 1 + dp[index1 - 1][index2 - 1];
                ans = max(ans, dp[index1][index2]);
            }
            // If no no need to check further set it to dp[index1][index2]
            else
                dp[index1][index2] = 0;
        }
    }
    return ans;
}
int lcs_Tabulation_Space_Optimized(string s1, string s2, int n, int m)
{
    vector<int> prev(m + 1, 0);
    vector<int> curr(m + 1, 0);
    int ans = 0;
    for (int index1 = 1; index1 <= n; index1++)
    {
        for (int index2 = 1; index2 <= m; index2++)
        {
            if (s1[index1 - 1] == s2[index2 - 1])
            {
                curr[index2] = 1 + prev[index2 - 1];
                ans = max(ans, curr[index2]);
            }
            else
                curr[index2] = 0;
        }
        prev = curr;
    }
    return ans;
}
int lcs(string &str1, string &str2)
{
    int index1 = str1.size();
    int index2 = str2.size();
    return helper(str1, str2, index1, index2, 0);
}