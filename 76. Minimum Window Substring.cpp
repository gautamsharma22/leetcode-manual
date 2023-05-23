class Solution
{
    /*
        Approach:- Sliding Window (Advanced)
            * Traverse through string (t) and store the count of all required chars.
            * Maintain a count of all required chars.
            * Now start i and j from 0 ( Here i and j is window )
            * In every step check the character at j(th) index is required or not by comparing it to required Array.
            * If it is required then increase the count of found.
            * If any time our count of required and found chars are same then ->
                    * Store the indexes (This might be expected Window)
                    * Move the start (i) of the window by one.
                    * Check if we lost any character that was required.
                        *If yes then break out and start again by incrementing end(j) of the window.
                        *If not then keep decrementing it till we have all the characters required
    */
public:
    string minWindow(string s, string t)
    {
        int n = s.length();
        int m = t.length();
        if (m > n)
            return "";
        if (t == s)
            return s;
        string res = "";
        int reqWindow[128] = {0};
        int i = 0, j = 0;
        for (auto &a : t)
        {
            reqWindow[a]++;
        }
        int currWindow[128] = {0};
        int reqChars = t.size();
        int foundChars = 0;
        int strtIndex = 0, endIndex = 0, window_len = INT_MAX;
        while (j < n)
        {
            currWindow[s[j]]++;
            if (currWindow[s[j]] <= reqWindow[s[j]])
            {
                foundChars++;
            }
            if (foundChars == reqChars)
            {
                while (currWindow[s[i]] > reqWindow[s[i]] || reqWindow[s[i]] == 0)
                {
                    if (currWindow[s[i]] > reqWindow[s[i]])
                        currWindow[s[i]]--;
                    i++;
                }
                if (j - i + 1 < window_len)
                {
                    window_len = (j - i) + 1;
                    res = s.substr(i, window_len);
                }
            }
            j++;
        }
        return res;
    }
};