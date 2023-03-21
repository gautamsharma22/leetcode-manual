// more like a mathematics question.
class Solution
{
public:
    long long zeroFilledSubarray(vector<int> &nums)
    {
        long long count = 0;
        long long result = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
                count++; // Increment i if 0 is found
            else
            { // If any non zero elemnt encountered push current subarray sum to result and reset count;
                count = count * (count + 1) / 2;
                result += count;
                count = 0;
            }
        }
        if (count != 0)
            result += count * (count + 1) / 2;
        return result;
    }
};