class Solution
{
public:
    /*

    Approach Based on Intuition:
        * If pattern contains '?' replace it with expected chahracter and proceed further.
        * If pattern contains '*' first try putting empty char threre ans check for ans, second try putting expected char or sequence or character until you get desired ans.
        * For Better Understanding read further base cases.

    */

    int helper(string &s, string &p, int i, int j)
    {
        cout << i << " " << j << endl;
        if (i == s.size() && j == p.size())
            return true; // Both string and pattern used.
        if (i <= s.size() && j >= p.size())
            return false; // String remaining but pattern is fully used.
        if (i >= s.size() && j < p.size())
        { // String used but pattern is remaing.
            for (int i = j; i < p.size(); i++)
            {
                if (p[i] != '*')
                { // If anything else is reaming in pattern except for '*' consider that as an extra char and return false;
                    return false;
                }
            }
            return true;
        }

        if (s[i] == p[j] || p[j] == '?')
        {
            return helper(s, p, i + 1, j + 1);
        }
        else if (p[j] == '*')
        {
            return (helper(s, p, i + 1, j)    // Case 1: Consider '*' as '*' + Char required.
                    || helper(s, p, i, j + 1) // Case 2: Consider '*' as empty String.
            );
        }
        else
        {
            return false;
        }
    }
    bool isMatch(string s, string p)
    {
        return helper(s, p, 0, 0);
    }
    int helper_Memoization(string &s, string &p, int i, int j, vector<vector<int>> &dp)
    {
        if (i == s.size() && j == p.size())
            return true;
        if (i <= s.size() && j >= p.size())
            return false;
        if (i >= s.size() && j < p.size())
        {
            for (int i = j; i < p.size(); i++)
            {
                if (p[i] != '*')
                {
                    return false;
                }
            }
            return true;
        }
        if (dp[i][j] != -1)
            return dp[i][j];
        if (s[i] == p[j] || p[j] == '?')
        {
            return dp[i][j] = helper_Memoization(s, p, i + 1, j + 1, dp);
        }
        else if (p[j] == '*')
        {
            return dp[i][j] = (helper_Memoization(s, p, i + 1, j, dp) || helper_Memoization(s, p, i, j + 1, dp));
        }
        else
        {
            return dp[i][j] = false;
        }
    }
    bool isMatch(string s, string p)
    {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return helper_Memoization(s, p, 0, 0, dp);
    }
    bool isMatch_Tabulation(string s, string p)
    {
        int n = s.size();
        int m = p.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        dp[n][m] = true;
        for (int i = 0; i <= p.size(); i++)
        {
            bool notfound = true;
            for (int k = i; k < p.size(); k++)
            {
                if (p[k] != '*')
                {
                    notfound = false;
                    break;
                }
            }
            dp[n][i] = notfound;
        }
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                if (s[i] == p[j] || p[j] == '?')
                {
                    dp[i][j] = dp[i + 1][j + 1];
                }
                else if (p[j] == '*')
                {
                    dp[i][j] = (dp[i + 1][j] || dp[i][j + 1]);
                }
                else
                {
                    dp[i][j] = false;
                }
            }
        }
        return dp[0][0];
    }
    bool isMatch_SpaceOptimised(string s, string p)
    {
        int n = s.size();
        int m = p.size();
        vector<bool> next(m + 1, false);
        vector<bool> curr(m + 1, false);
        next[m] = true;
        for (int i = 0; i <= p.size(); i++)
        {
            bool notfound = true;
            for (int k = i; k < p.size(); k++)
            {
                if (p[k] != '*')
                {
                    notfound = false;
                    break;
                }
            }
            next[i] = notfound;
        }
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                if (s[i] == p[j] || p[j] == '?')
                {
                    curr[j] = next[j + 1];
                }
                else if (p[j] == '*')
                {
                    curr[j] = (next[j] || curr[j + 1]);
                }
                else
                {
                    curr[j] = false;
                }
            }
            next = curr;
        }
        return next[0];
    }
};
}
;
