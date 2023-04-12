/*
    Approach Solution 1 ->

    TC-> O(N^3)
    SC-> O(N) Temp string

    * Traverse through string.
    * Call checkbBalance for every substring.
    * In checkBalance count number of starting zeroe's.
    * Traverse through String again and count for total zeroe's and one's.
    * If all the zero's are at starting and number of zero's==number of ones return true otherwise false.


    Approach Solution 2 ->


    TC-> O(N)
    SC-> O(1)

    * Traverse through string.
    * Count number of starting zero's and after that how many ones are there.
    * Update ans with min(zero,ones).

    Intuition of how the solution 2 works ->

    Example 1) Suppose we have "01000111"

        Then at i=0
        zero=1
        one=1
        ans=2*1 =2

        i will be updated to 2(next zero)

        Then at i=2
        zero=3
        one=3
        ans=2*3 = 6

        Hence Ans is 6;

    Example 2) Suppose we have "0101"

        Then at i=0
        zero=1
        one=1
        ans=2*1 =2

        i will be updated to 2(next zero)

        Then at i=2
        zero=1
        one=1
        ans=2*1 =2

        Hence Ans is 1;

*/

class Solution
{
public:
    bool checkBalance(string s)
    {
        int a = 0;
        int zero = 0, one = 0;
        int prevZero = 0;
        while (s[a++] == '0')
        {
            prevZero++;
        }
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '0')
            {
                zero++;
            }
            if (s[i] == '1')
            {
                one++;
            }
        }
        return (prevZero == zero && zero == one);
    }
    int findTheLongestBalancedSubstring(string s)
    {
        int maxAns = 0;
        for (int i = 0; i < s.length(); i++)
        {
            string ans = "";
            for (int j = i; j < s.length(); j++)
            {
                ans += s[j];
                if (checkBalance(ans))
                {
                    maxAns = max(maxAns, j - i + 1);
                }
            }
        }
        return maxAns;
    }
};

class Solution2
{
public:
    int findTheLongestBalancedSubstring(string s)
    {
        int ans = 0;
        int n = s.length();
        int i = 0;
        while (i < n)
        {
            int zero = 0, one = 0;
            while (i < n && s[i] == '0')
            {
                zero++;
                i++;
            }
            while (i < n && s[i] == '1')
            {
                one++;
                i++;
            }
            ans = max(ans, 2 * min(zero, one));
        }

        return ans;
    }
};