class Solution
{
public:
    /*
    Approach :- 
        * Create pair of nums1 with nums2.(Because we need them together)
        * Sort the pairs in increasing order of nums2.
        * 

    
    */
    long long maxScore(vector<int> &nums1, vector<int> &nums2, int k)
    {
        vector<pair<int, int>> mapp;
        int n = nums1.size();
        for (int i = 0; i < n; i++)
        {
            mapp.push_back({nums2[i], nums1[i]});
        }
        sort(mapp.begin(), mapp.end());
        // for(auto a:mapp){
        //     cout<<"First - > "<<a.first;
        //     cout<<" Second - > "<<a.second<<endl;
        // }
        long long sum = 0;
        long long bestAns = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = n - 1; i >= 0; i--)
        {
            sum += mapp[i].second;
            pq.push(mapp[i].second);
            if (pq.size() > k)
            {
                sum = sum - pq.top();
                pq.pop();
            }
            if (pq.size() == k)
                bestAns = max(bestAns, sum * mapp[i].first);
        }
        return bestAns;
    }
};