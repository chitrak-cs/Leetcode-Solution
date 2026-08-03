class Solution {
private:
    int func(int index, vector<int>& nums,vector<int>& dp){
        int n = nums.size();
        if(index >= n){
            return 0;
        }

        if(dp[index] != -1) return dp[index];

        int option1 = nums[index] - func(index+1,nums,dp);

        int option2 = INT_MIN;
        if(index+1 < n){
            option2 = (nums[index] + nums[index+1]) - func(index+2,nums,dp);
        }

        int option3 = INT_MIN;
        if(index+2 < n){
            option3 = (nums[index] + nums[index+1] + nums[index+2]) - func(index+3,nums,dp);
        }

        return dp[index] = max(option1,max(option2,option3));
    }
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int>dp(n,-1);

        int res = func(0,stoneValue,dp);
        if(res > 0) return "Alice";
        else if(res < 0) return "Bob";
        else return "Tie";
    }
};