class Solution
{
public:
    /*
    Tip -> We don't always whave to work on chars if possible we can work on strings too.

        Approach -> TC -> 0(N)
                    SC -> 0(N) (Output String)

        * Traverse through given path;
        * If '/' found skip;
        * Extract single dir/file from path; (Traversing until we find '/')
        * If dir equals '.' skip;
        * If dir equals '..' pop last dir from stack;
        * Else push current directory to stack;

        * Create output string from stack with ans= "/" + current dir + last dir;
        * If result is empty return home directory.

    */
    string simplifyPath(string path)
    {
        int n = path.size();
        stack<string> st;
        string ans = "";
        for (int i = 0; i < n; i++)
        {
            string temp;
            if (path[i] == '/')
            {
                continue;
            }
            while (i < n && path[i] != '/')
            {
                temp += path[i];
                i++;
            }
            if (temp == "..")
            {
                if (!st.empty())
                    st.pop();
            }
            else if (temp == ".")
            {
                continue;
            }
            else if (temp.size() > 0)
            {
                st.push(temp);
            }
        }
        while (!st.empty())
        {
            ans = "/" + st.top() + ans;
            st.pop();
        }
        if (ans.size() == 0)
            ans += '/';
        return ans;
    }
};
