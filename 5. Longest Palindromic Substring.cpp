/*

    Brute Force Approach.
    Check each substring for palindrome;

    Time Complexity : O(N^3) For Substring O(n^2) * For Checking Palindrome O(n)
    Space Complexity : O(1), Constant space.


*/

class Solution
{
public:
    bool isValid(string &s)
    {
        int i = 0;
        int j = s.length() - 1;
        while (i < s.length() && j >= 0)
        {
            if (s[i++] != s[j--])
            {
                return false;
            }
            if (i == j)
            {
                return true;
            }
        }
        return true;
    }
    string longestPalindrome(string s)
    {
        string ans = "";
        for (int i = 0; i < s.length(); i++)
        {
            string temp = "";
            for (int j = i; j < s.length(); j++)
            {
                temp += s[j];
                if (isValid(temp))
                {
                    if (ans.size() < temp.size())
                        ans = temp;
                }
            }
        }
        return ans;
    }
};

/*
    Bottom Up Approach (DP)
    After Checking a substring store its result.
    Time Complexity : O(n^2)
    Space Complexity : O(n^2)


*/
class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.length();
        if (n == 1)
            return s;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        string ans = "";
        int ansLength = 0;
        int start = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i; j < n; j++)
            {
                if (i == j)
                {
                    dp[i][j] = true; // For Single Characters
                }
                else if (j - i == 1) // For two Characters
                {
                    dp[i][j] = (s[i] == s[j]);
                }
                else if (s[i] == s[j] && dp[i + 1][j - 1]) // If there are more than 2 character then check (If boundary is palindrome && string inside boundary is palindrome)
                {
                    dp[i][j] = true;
                }

                // If Its a Palindrome then calculate its Size.
                if (dp[i][j])
                {
                    int currSize = (j - i) + 1;
                    if (currSize > ansLength)
                    {
                        start = i;
                        ansLength = currSize;
                    }
                }
            }
        }
        ans = s.substr(start, ansLength);
        int row = 0;
        // If we want to check dp table.
        for (auto a : dp)
        {
            cout << "Row " << row++ << ") ->  ";
            for (auto x : a)
            {
                cout << x << " ";
            }
            cout << endl;
        }
        return ans;
    }
};