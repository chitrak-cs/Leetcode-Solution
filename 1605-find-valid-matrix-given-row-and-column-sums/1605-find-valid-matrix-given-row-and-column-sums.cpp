class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowsum, vector<int>& colsum) {
        int m = rowsum.size();
        int n = colsum.size();
        vector<vector<int>>ans(m,vector<int>(n));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans[i][j] = min(rowsum[i],colsum[j]);
                rowsum[i] -= ans[i][j];
                colsum[j] -= ans[i][j];
            }
        }

        return ans;
    }
};