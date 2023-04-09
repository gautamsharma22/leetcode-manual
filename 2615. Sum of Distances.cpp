class Solution
{
public:
    vector<long long> distance(vector<int> &nums)
    {
        unordered_map<int, vector<int>> distances;
        vector<long long> ans(nums.size());
        for (int i = 0; i < nums.size(); i++)
        {
            distances[nums[i]].push_back(i);
        }
        for (auto x : distances)
        {
            vector<int> v = x.second;
            long long sum = 0;
            for (auto a : v)
            {
                sum += a;
            }
            int n = v.size();
            if (n == 1)
            {
                ans[v[0]] = 0;
                continue;
            }
            long long leftsum = 0;
            long long rightsum = sum;
            long long currentsum = 0;
            for (int i = 0; i < n; i++)
            {
                currentsum = 0;
                currentsum += (long)i * v[i] - leftsum;
                currentsum += rightsum - (long)((n - i) * (long)v[i]);
                leftsum += v[i];
                rightsum -= v[i];
                ans[v[i]] = currentsum;
            }
        }
        return ans;
    }
};