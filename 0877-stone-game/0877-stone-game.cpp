class Solution {
private:
    int diff(int low, int high, vector<int>& nums, vector<vector<int>>& dp){
        if(low == high){
            return nums[low];
        }

        if(dp[low][high] != -1) return dp[low][high];

        int option1 = nums[low] - diff(low+1,high,nums,dp);
        int option2 = nums[high] - diff(low,high-1,nums,dp);

        return dp[low][high] = max(option1,option2);
    }
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return diff(0,n-1,piles,dp) > 0;
    }
};