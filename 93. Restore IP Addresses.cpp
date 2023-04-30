class Solution
{
public:
    vector<string> ans;
    bool checkSegment(string ip)
    {
        if (ip.length() == 1)
            return true;
        if (ip.length() > 1 && stoi(ip) <= 255 && ip[0] != '0')
        {
            return true;
        }
        return false;
    }
    void helper(string s, int dots, int index, string nums)
    {
        if (index == s.length() && dots == 4)
        {
            nums.pop_back(); // Remove Extra Dot.
            ans.push_back(nums);
            return;
        }
        if (dots > 4 || index >= s.length())
            return;
        for (int i = index; i < index + 3; i++)
        {
            string temp = s.substr(index, i - index + 1);
            if (checkSegment(temp))
            {
                temp += '.';
                nums += temp;
                helper(s, dots + 1, i + 1, nums);
                nums = nums.substr(0, nums.length() - temp.length()); // Main Backtrack
            }
        }
        return;
    }
    vector<string> restoreIpAddresses(string s)
    {
        helper(s, 0, 0, "");
        return ans;
    }
};