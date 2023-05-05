class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        int n=tiles.size();
        int currLen=0;
        int ans=0;
        int j=0;
        sort(tiles.begin(),tiles.end());
        for(int i=0;i<n;i++){
            int end=tiles[i][0]+carpetLen-1; // Total Area Covered if we started from Current tile.
            // Next tile ending Index is also covered in current Carpet Length.
            while(j<n && tiles[j][1]<end){
                currLen+=tiles[j][1]-tiles[j][0]+1; // Keep Extending the Carpet 
                j++;
            }
            // If We reached end of index ||  Next tile is Far away from Carpet
            if(j==n || tiles[j][0]>end){
                ans=max(ans,currLen);
            }else{  
                ans=max(ans,currLen+end-tiles[j][0]+1); // If we Covered Some Part of Next tile.
            }
            currLen-=tiles[i][1]-tiles[i][0]+1; // Move to next Window || Option
        }
        return ans;
    }
};