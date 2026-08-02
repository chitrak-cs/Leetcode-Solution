class Solution {
private:
    int func(int prev, int ind, vector<int>& nums, vector<vector<int>>& dp){
        int n = nums.size();
        if(ind == n) return nums[prev];
        if(ind == n-1) return max(nums[prev],nums[ind]);

        if(dp[prev][ind] != -1) return dp[prev][ind];

        int op1 = max(nums[prev],nums[ind]) + func(ind+1,ind+2,nums,dp);
        int op2 = max(nums[ind],nums[ind+1]) + func(prev,ind+2,nums,dp);
        int op3 = max(nums[prev],nums[ind+1]) + func(ind,ind+2,nums,dp);

        return dp[prev][ind] = min(op1,min(op2,op3));
    }
public:
    int minCost(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return func(0,1,nums,dp);
    }
};