class Solution
{
public:
    /*
        Aproach:

        Recursion->
            * Calculate Difference between current stone and next stone;
            * If Diffrence can be covered by (Current Jump,Current Jump+1,Current Jump-1);
            * Cover the distance and repeat the same until reached to the last index.

            ->(This approach will give TLE because stones.length <= 2000 and stones[i] <= 2^31 - 1)
            ->(If we try to memoize the same approach it will give MLE, So Continuing to another approach.)

        HashMap->
            * Create a hashmap of [ stones[i] -> { From how many jumps we can reach here } ]
            * If last stone set is non empty means from any jump we have reached there.
            * Return if(lastStoneSet is empty or not).

    */
    bool Recursive_helper(vector<int> &stones, int index, int jump)
    {
        if (index == stones.size() - 1)
            return true;
        bool ans = false;
        for (int i = index + 1; i < stones.size(); i++)
        {
            int diff = stones[i] - stones[index];
            if (diff > jump + 1)
                break;
            if (jump - 1 > 0)
            {
                if (diff == jump - 1)
                    ans = Recursive_helper(stones, i, jump - 1) or ans;
            }
            if (diff == jump)
                ans = Recursive_helper(stones, i, jump) or ans;
            if (diff == jump + 1)
                ans = Recursive_helper(stones, i, jump + 1) or ans;
        }
        return ans;
    }
    bool canCross(vector<int> &stones)
    {
        if (stones[1] - stones[0] > 1)
            return false;
        return Recursive_helper(stones, 0, 1);
    }
    bool canCross_HashMap(vector<int> &stones)
    {
        unordered_map<int, unordered_set<int>> mapp;

        int n = stones.size();
        mapp[stones[0] + 1] = {1};
        for (int i = 1; i < n; i++)
        {
            int stone = stones[i];
            for (auto a : mapp[stone])
            {
                mapp[stone + a].insert(a);
                mapp[stone + (a + 1)].insert(a + 1);
                mapp[stone + (a - 1)].insert(a - 1);
            }
        }
        return mapp[stones[n - 1]].size() != 0;
    }
};
}
;