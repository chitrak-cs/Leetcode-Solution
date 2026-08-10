class Solution {
    // i and j represents the number of charectors being used
private:
    bool func(int i,int j,string s1,string s2,string s3,vector<vector<int>>& dp){
        int m = s1.size();
        int n = s2.size();

        if(i==m && j==n){
            return dp[i][j] = true;
        }

        if(dp[i][j] != -1) return dp[i][j];

        bool op1 = false;
        bool op2 = false;

        if(i<m){
            int k = i+j;
            if(s1[i] == s3[k]){
                op1 = func(i+1,j,s1,s2,s3,dp);
            }
        }

        if(j<n){
            int k = i+j;
            if(s2[j] == s3[k]){
                op2 = func(i,j+1,s1,s2,s3,dp);
            }
        }

        return dp[i][j] = op1 || op2;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size();
        int n = s2.size();
        int k = s3.size();

        if(m+n != k) return false;
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return func(0,0,s1,s2,s3,dp);
    }
};