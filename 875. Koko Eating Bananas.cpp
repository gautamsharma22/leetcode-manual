class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left=1;
        int right=INT_MIN;
        for(auto i:piles){
            if(i>right)right=i;
        }
        while(left<=right){
            long count=0;
            int mid=left+(right-left)/2;
            for(int i=0;i<piles.size();i++){
                count+=ceil(1.0 * piles[i]/mid);
            }
            if(count<=h){
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        return left;
    }
};