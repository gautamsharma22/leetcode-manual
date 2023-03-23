class Solution {
public:
// Sort the Enveloped by it's width
    static bool sortcol(const vector<int>& v1, const vector<int>& v2)
    {
        if(v1[0]==v2[0]){ //If width is same then sort it by height (descending) 
            return v1[1]>v2[1];
        }
        return v1[0]<v2[0];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),sortcol);
        int n=envelopes.size();
        //Longest Increasing Subsequence Logic on height 
        vector<int> ans;
        ans.push_back(envelopes[0][1]);
        for(int i=1;i<envelopes.size();i++){
            if(envelopes[i][1]>ans.back()){
                ans.push_back(envelopes[i][1]);
            }else{
                vector<int>::iterator lower;
                lower=lower_bound(ans.begin(),ans.end(),envelopes[i][1]);
                int index=lower-ans.begin();
                ans[index]=envelopes[i][1];
            }
        }
        return ans.size();
    }
};