class Solution {
private:
    int dr[4] = {1,-1,0,0};
    int dc[4] = {0,0,1,-1};

    bool isvalid(int i,int j,int m,int n){
        if(i>=0 && i<m && j>=0 && j<n) return true;
        else return false;
    }

    void bfs(int row, int col,vector<vector<int>>& visited, vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();

        visited[row][col] = 1;
        queue<pair<int,int>>q;
        q.push({row,col});

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                int nr = r+dr[i];
                int nc = c+dc[i];

                if(isvalid(nr,nc,m,n) && visited[nr][nc] == 0 && grid[nr][nc] == 0){
                    visited[nr][nc] = 1;
                    q.push({nr,nc});
                }
            }
        }
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>visited(m,vector<int>(n,0));
        // make the boundary cells as water
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 || i==m-1 || j==0 || j==n-1){
                    if(grid[i][j] == 0)bfs(i,j,visited,grid);
                }
            }
        }

        int ans = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(visited[i][j] == 0 && grid[i][j] == 0){
                    bfs(i,j,visited,grid);
                    ans++;
                }
            }
        }

        return ans;
    }
};