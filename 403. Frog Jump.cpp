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
            * In this approach it may seem that why we are adding jumps for stones(which may have not been present in the our source array -> for that if we we'll check if stones[i]+jump is valid or not our time complexity may increase (search in set is 0(1) but in worst case it may be 0(n)) ).
            * We can do searching approach also.

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
        // Use Set to ignore duplicate values.
        unordered_map<int, unordered_set<int>> mapp;

        int n = stones.size();
        // From stone[0]->stone[0]+1 we have taken 1 Jumps so Add it.
        mapp[stones[0] + 1] = {1};
        for (int i = 1; i < n; i++)
        {
            int stone = stones[i];
            for (auto jumps : mapp[stone]) // From how many jumps we can reach here
            {
                mapp[stone + jumps].insert(jumps);
                mapp[stone + (jumps + 1)].insert(jumps + 1);
                mapp[stone + (jumps - 1)].insert(jumps - 1);
            }
        }
        return mapp[stones[n - 1]].size() != 0;
    }
};
}
;