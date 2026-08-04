class Solution {
private:
    int func(int row, int col,vector<vector<int>>& grid,vector<vector<int>>& dp){
        int m = grid.size();
        int n = grid[0].size();

        if(row == m-1 && col == n-1){
            return 1;
        }

        if(dp[row][col] != -1) return dp[row][col];

        int left = 0;
        int down = 0;

        if(row+1<m && grid[row+1][col] == 0){
            left = func(row+1,col,grid,dp);
        }

        if(col+1<n && grid[row][col+1] == 0){
            down = func(row,col+1,grid,dp);
        }

        return dp[row][col] = left + down;


    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obs) {
        int m = obs.size();
        int n = obs[0].size();


        if(obs[0][0] == 1) return 0;

        vector<vector<int>>dp(m,vector<int>(n,-1));
        return func(0,0,obs,dp);
    }
};