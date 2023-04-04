class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp (n+2,vector<int>(2,0));
        for(int index=n-1;index>=0;index--){
            for(int canBuy=0;canBuy<=1;canBuy++){
                int profit=0;
                if(canBuy){
                    int buy=-prices[index]+dp[index+1][false];
                    int notBuy=dp[index+1][true];
                    profit=max(buy,notBuy);
                }else{
                    int sell=prices[index]+dp[index+2][true]; // Only change is here if we are selling here means we have completed one transaction means we have to cooldown for one day so we update index+2(To jump to next->next day) and a sligh change in dp array.
                    int notSell=dp[index+1][false];
                    profit=max(sell,notSell);
                }
                dp[index][canBuy]=profit;
            }
        }
        return dp[0][1];
    }
};