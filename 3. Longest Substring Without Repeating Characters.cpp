class Solution
{
public:
    /*
        Approach : Sliding Window
        TC-> O(N)
        SC-> O(N)

        * Create a Set to check whether a Character is already present or Not.
        * Traverse through String and check if character is already present or not if not then insert it.
        * If its char is present already, then reduce the sliding window size by 1 from left. (Because we are moving from left to right.)

    */
    int lengthOfLongestSubstring(string s)
    {
        int n = s.length();
        if (n < 2)
            return n;
        int ans = 0;
        int start = 0;
        unordered_set<char> s1;
        for (int i = 0; i < n; i++)
        {
            if (s1.find(s[i]) == s1.end())
            {
                s1.insert(s[i]);
            }
            else
            {
                while (start < n && s[start] != s[i])
                {
                    s1.erase(s[start++]);
                }
                start++;
            }
            ans = max(ans, i - start + 1);
        }
        return ans;
    }
};