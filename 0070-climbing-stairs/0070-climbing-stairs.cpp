class Solution {
private:
    int func(int index, int n,vector<int>& dp){
        if(index == n){
            return 1;
        }
        else if(index>n){
            return 0;
        }

        if(dp[index] != -1) return dp[index];

        int one = func(index+1,n,dp);
        int two = func(index+2,n,dp);

        return dp[index] = one + two;
    }
public:
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return func(0,n,dp);
    }
};