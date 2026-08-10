class Solution {
private:
    bool func(int n,vector<int>& dp){
        if(n==0){
            return false;
        }

        if(dp[n] != -1) return dp[n];

        for(int i=1;i*i<=n;i++){
            int sq = i*i;
            if(func(n-sq,dp) == false){
                return dp[n] = true;
            }
        }

        return dp[n] = false;
    }
public:
    bool winnerSquareGame(int n) {
        vector<int>dp(n+1,-1);
        return func(n,dp);
    }
};