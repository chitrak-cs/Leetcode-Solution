class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& mat) {
        int m = mat.size(); // row
        int n = mat[0].size(); // col
        
        vector<int> row(m);
        vector<int> col(n);

        // store the min for each row
        for(int i=0;i<m;i++){
            int minele = INT_MAX;
            for(int j=0;j<n;j++){
                minele = min(minele,mat[i][j]);
            }
            row[i] = minele;
        }

        // store the max for each column
        for(int j=0;j<n;j++){
            int maxele = INT_MIN;
            for(int i=0;i<m;i++){
                maxele = max(maxele,mat[i][j]);
            }
            col[j] = maxele;
        }

        vector<int> ans;
        for(int i=0;i<m;i++){
            for(int j=0; j<n;j++){
                if(mat[i][j] == row[i] && mat[i][j] == col[j]){
                    ans.push_back(mat[i][j]);
                }
            }
        }

        return ans;
    }
};