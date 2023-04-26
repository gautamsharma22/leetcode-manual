class Solution
{
public:
    /*
        Approach (Use Monotonic Stack Logic)

        * Traverse through given string
        * If any number is smaller than the previous number remove it.(If there are multiple remove till k limit)
        * It was not Intuitive.
    */
    string removeKdigits(string num, int k)
    {
        int n = num.size();
        string ans = "";
        int required_size = n - k;
        for (int i = 0; i < n; i++)
        {
            while (!ans.empty() && ans.back() > num[i] && k > 0)
            {
                ans.pop_back();
                k--;
            }
            ans.push_back(num[i]);
        }

        // Remove reaming k digits (If Left)
        // string::erase() remove all element after provided index
        ans.erase(required_size);
        int a = 0;
        while (ans[a] == '0')
        {
            a++;
        }

        // Remove Leading Zero's
        // string::erase(start,length) remove the from start index till lengh index.
        ans.erase(0, a);
        return ans == "" ? "0" : ans;
    }
};