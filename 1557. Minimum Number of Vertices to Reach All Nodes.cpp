class Solution {
public:
    /*
    Approach:
        Find all the vertices who have no incoming edges.
    */
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> ans;
        vector<int> mapp(n,0);
        for(int i=0;i<edges.size();i++){
            mapp[edges[i][1]]=1;
        }
        for(int i=0;i<mapp.size();i++){
            if(mapp[i]==0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};