class Solution
{
public:
    /*
    Approach - >
        TC-> O(N)
        SC-> 0(N) Or some may say O(1) beacuse its result.
        * Traverse the given string.
        * Push character to resultant string.
        * If '*' found pop out the last pushed character.
        * Return the resultant.

    Optimised Approach - >
        TC-> O(N)
        SC-> 0(1) Using two pointer
        * Traverse the given string.
        * Replace the character with new index of j;
        * If '*' found decrement j so, character previously pushed get replaced.
        * Return the string.
    */
    string removeStars(string s)
    {
        string ans = "";
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '*')
            {
                ans.pop_back();
            }
            else
            {
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
    string removeStars_Optimised(string s)
    {
        int j = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '*')
            {
                j--;
            }
            else
            {
                s[j++] = s[i];
            }
        }
        return s.substr(0, j);
    }
};
