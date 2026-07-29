class Solution {
private:
    int func(int index,vector<int>& nums,vector<int>& dp){
        int n = nums.size();
        if(index >= n-1){
            return 0;
        }

        if(dp[index] != -1) return dp[index];

        int minstep = INT_MAX;
        int j = nums[index];
        for(int i=1;i<=j && index + i < n;i++){
            int val = func(index+i,nums,dp);
            minstep = min(minstep,val);
        }

        if(minstep == INT_MAX) return dp[index] = minstep;
        return dp[index] =1+ minstep;
    }
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        return func(0,nums,dp);
    }
};