class SmallestInfiniteSet
{
public:
    vector<int> mapp;
    SmallestInfiniteSet()
    {
        mapp = vector<int>(1001, 1);
    }

    int popSmallest()
    {
        int a = 1;
        while (a < mapp.size())
        {
            if (mapp[a] > 0)
            {
                mapp[a]--;
                return a;
            }
            a++;
        }
        return -1;
    }

    void addBack(int num)
    {
        if (mapp[num] == 0)
            mapp[num]++;
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */