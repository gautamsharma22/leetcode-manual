class Solution {
public:
    bool ship(vector<int>& weights, int days,int capacity){
        int currDay=1;
        int currSum=0;
        for(int i=0;i<weights.size();i++){
            currSum+=weights[i];
            if(currSum>capacity){
                currDay++;
                currSum=weights[i];
            }
        }
        return(currDay<=days);
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int right=0;
        int left=0;
        for(int i=0;i<weights.size();i++){
            right+=weights[i];
            if(left<=weights[i]){
                left=weights[i];
            }
        }
        if(weights.size()==days){
            return left;
        }
        while(left<right){
            int capacity=left+(right-left)/2;
            if(ship(weights,days,capacity)){
                right=capacity;
            }else{
                left=capacity+1;
            }
        }
        return left;
    }
};