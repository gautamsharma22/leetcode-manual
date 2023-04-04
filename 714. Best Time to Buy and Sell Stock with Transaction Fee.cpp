class Solution {
public:
/*
Approach: 
Same as Other Buy and Sell Problems Just Subtraction Transaction fee from profit after completeing a transaction.
*/
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>> dp (n+1,vector<int>(2,0));
        vector<int> curr(2,0);
        vector<int> next(2,0);
        for(int index=n-1;index>=0;index--){
            for(int canBuy=0;canBuy<=1;canBuy++){
                int profit=0;
                if(canBuy){
                    int buy=-prices[index]+next[false];
                    int notBuy=next[true];
                    profit=max(buy,notBuy);
                }else{
                    int sell=prices[index]+next[true]-fee; 
                    int notSell=next[false];
                    profit=max(sell,notSell);
                }
                curr[canBuy]=profit;
            }
            next=curr;
        }
        return curr[1]; 
    }
};