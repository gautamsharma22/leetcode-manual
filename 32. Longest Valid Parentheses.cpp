class Solution
{
public:
    /*
    Brute Force Approach
        Check All substrings for Validity
        TC-> O(N^3)
        SC-> O(N)
    */
    bool isValid(string &s)
    {
        if (s.length() == 1)
            return false;
        stack<char> st;
        for (auto x : s)
        {
            if (x == '(')
            {
                st.push(x);
            }
            else
            {
                if (st.empty())
                    return false;
                if (st.top() == '(')
                {
                    st.pop();
                }
            }
        }
        return st.size() == 0;
    }
    int longestValidParentheses(string s)
    {
        int n = s.length();
        int maxi = 0;
        for (int i = 0; i < n; i++)
        {
            string temp = "";
            for (int j = i; j < n; j++)
            {
                temp += s[j];
                if (isValid(temp))
                {
                    maxi = max(maxi, (j - i + 1));
                }
            }
        }
        return maxi;
    }

    /*
        Approach 2
            TC -> O(N)
            SC -> O(N)

            * Traverse through String and if opening braces found push opening braces into braces stack and its index in index stack.(To tarack the last invalid index.(This will help in counting the substring))
            * If closing braces found
                * Check for an opening braces in character index
                    * If found then its valid pair, pop out last pushed index and calulate ans.
                    * If not found means there is an extra closing bracket so mark current index as invalid.
            * If any time our index stack becomes empty means start new substring from here (Because we found an extra braces.)

    */
    int longestValidParentheses(string s)
    {
        int n = s.length();
        int maxi = 0;
        stack<char> st;
        stack<int> invalidIndex;
        invalidIndex.push(-1);
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
            {
                st.push(s[i]);
                invalidIndex.push(i);
            }
            else
            {
                if (!st.empty())
                {
                    invalidIndex.pop();
                    st.pop();
                    if (invalidIndex.empty())
                    {
                        invalidIndex.push(i);
                    }
                    else
                    {
                        int currMaxPair = i - invalidIndex.top();
                        maxi = max(maxi, currMaxPair);
                    }
                }
                else
                {
                    invalidIndex.push(i);
                }
            }
        }
        return maxi;
        /*
            Approach 3 (Only Storing indexes)
                TC -> O(N)
                SC -> O(N)
                * We can follow the same approach without using chracter stack whihc was used to store braces.
                * We will store only indices and use them to get out ans.


        */
        int longestValidParentheses(string s)
        {
            int n = s.length();
            int maxi = 0;
            stack<int> invalidIndex;
            invalidIndex.push(-1);
            for (int i = 0; i < n; i++)
            {
                if (s[i] == '(')
                {
                    invalidIndex.push(i);
                }
                else
                {
                    invalidIndex.pop();
                    if (invalidIndex.empty())
                    {
                        invalidIndex.push(i);
                    }
                    else
                    {
                        int currMaxPair = i - invalidIndex.top();
                        maxi = max(maxi, currMaxPair);
                    }
                }
            }
            return maxi;
        }
    };