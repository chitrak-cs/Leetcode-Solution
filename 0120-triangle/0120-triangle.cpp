class Solution {
private:
    int maxi = 1e8;
    int func(int row, int col,vector<vector<int>>& nums,vector<vector<int>>& dp){
        int m = nums.size();

        if(row == m-1){
            return nums[row][col];
        }

        if(dp[row][col] != -maxi) return dp[row][col];

        int op1 = func(row+1,col,nums,dp);
        int op2 = INT_MAX;
        if(col+1<nums[row+1].size()){
            op2 = func(row+1,col+1,nums,dp);
        }

        return dp[row][col] = nums[row][col] + min(op1,op2);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int n = triangle[m-1].size();

        vector<vector<int>> nums(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<triangle[i].size();j++){
                nums[i][j] = triangle[i][j];
            }
        }

        vector<vector<int>>dp(m,vector<int>(n,-maxi));
        return func(0,0,triangle,dp);
    }
};