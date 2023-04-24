class Solution
{
public:
    /*
    Approach ->

            TC -> O(m.logk) where m=length of string k=length of inner substring
            Space -> O(m)

        * Traverse through String and check if current digit is Valid.
        * If current digit is valid make a Recursive call to next number.
        * If current digit is not valid break the loop;
        * At any time if we reach last index+1 means all digits we valid so return 1 to store in Answer.
    */
    const int MOD = 1e9 + 7;
    int Memoization(string &s, int &k, int index, vector<int> &dp)
    {
        long long totalWays = 0;
        if (index >= s.length())
            return 1;
        if (dp[index] != -1)
            return dp[index];
        long long currNum = 0;
        for (int i = index; i < s.length(); i++)
        {
            int digit = s[i] - '0'; // (From Current Index generate all sequences)
            currNum = (currNum * 10) + digit;
            if (currNum < 1 || currNum > k)
                break;
            totalWays += Memoization(s, k, i + 1, dp);
        }
        return dp[index] = totalWays % MOD;
    }
    int numberOfArrays(string s, int k)
    {
        vector<int> dp(s.size() + 1, -1);
        return Memoization(s, k, 0, dp);
    }

    // Same Approach (Bottom Up DP) TC and Space will be the same.
    const int MOD = 1e9 + 7;
    int numberOfArrays_BottomUp(string s, int k)
    {
        int n = s.length();
        vector<int> dp(n + 1, 0);
        dp[n] = 1;
        for (int index = n - 1; index >= 0; index--)
        {
            long long totalWays = 0, currNum = 0;
            for (int i = index; i < n; i++)
            {
                int digit = s[i] - '0';
                currNum = (currNum * 10) + digit;
                if (currNum < 1 || currNum > k)
                    break;
                totalWays += dp[i + 1];
            }
            dp[index] = totalWays % MOD;
        }
        return dp[0];
    }
};