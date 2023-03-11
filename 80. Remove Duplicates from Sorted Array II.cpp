class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.size() < 3)
            return nums.size();
        int in = 2; // Consider these two as fixed elements;
        for (int i = 2; i < nums.size(); i++)
        {
            if (nums[i] != nums[in - 2])
            { // if two elements are not change their values
                nums[in] = nums[i];
                in++; // Add One more fixed element
            }
        }
        return in;
    }
};