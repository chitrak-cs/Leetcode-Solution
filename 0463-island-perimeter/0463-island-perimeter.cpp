class Solution {
private:
    int dr[4] = {1, -1, 0, 0};
    int dc[4] = {0, 0, 1, -1};
    int dfs(int r,int c,vector<vector<int>>& grid,vector<vector<int>>& visited){
        visited[r][c] = 1;
        int perimeter = 0;
        int m = grid.size();
        int n = grid[0].size();

        for(int i=0;i<4;i++){
            int nr = r+dr[i];
            int nc = c+dc[i];

            if(nr<0 || nc<0 || nr>=m || nc>=n) perimeter++;
            else if(grid[nr][nc] == 0) perimeter++;
            else if(grid[nr][nc] == 1 && visited[nr][nc] == 0){
                perimeter += dfs(nr,nc,grid,visited);
            }
        }


        return perimeter;
    }
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    return dfs(i,j,grid,visited);
                }
            }
        }

        return 0;
    }
};