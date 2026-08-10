class Solution {
private:
    // for every index if the charectors are different we have 3 option replace,remove or insert
    int func(int i,int j,string word1,string word2,vector<vector<int>>& dp){
        int m = word1.size();
        int n = word2.size();

        if(i==m){
            return n-j;
        }

        if(j==n){
            return m-i;
        }

        if(dp[i][j] != -1) return dp[i][j];

        if(word1[i] == word2[j]){
            return dp[i][j] = func(i+1,j+1,word1,word2,dp);
        }

        int op1 = func(i+1,j,word1,word2,dp);
        int op2 = func(i,j+1,word1,word2,dp);
        int op3 = func(i+1,j+1,word1,word2,dp);

        return dp[i][j] = 1 + min(op1,min(op2,op3));
    }
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();

        vector<vector<int>>dp(m,vector<int>(n,-1));
        return func(0,0,word1,word2,dp);
    }
};