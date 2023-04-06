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
};
