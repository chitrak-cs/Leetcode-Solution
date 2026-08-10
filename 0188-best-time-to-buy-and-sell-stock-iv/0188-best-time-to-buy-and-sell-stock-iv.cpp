class Solution {
private:
    int func(int index,int state,int k,vector<int>& prices,vector<vector<vector<int>>>& dp){
        // state 0 means the person is able to buy and 1 means that he is able to sale
        // for each state 3 things are possible buy sell or skip

        int n = prices.size();
        if(index == n){
            return 0;
        }

        if(dp[index][state][k] != -1) return dp[index][state][k];

        // do not do any activity and move on to next day
        int ans = func(index+1,state,k,prices,dp);
        
        // buy the stock
        if(state == 0 && k>0){
            int buy = func(index+1,1,k-1,prices,dp) - prices[index];
            ans = max(ans,buy);
        }

        // sell the stock
        if(state == 1){
            int sell = func(index+1,0,k,prices,dp) + prices[index];
            ans = max(ans,sell);
        }

        return dp[index][state][k] = ans;
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return func(0,0,k,prices,dp);
    }
};