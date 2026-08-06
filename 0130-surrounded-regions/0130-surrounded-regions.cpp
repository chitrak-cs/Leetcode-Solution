class Solution {
private:
    bool isvalid(int r,int c,int m,int n){
        if(r>=0 && r<m && c>=0 && c<n) return true;
        return false;
    }

    int dr[4] ={-1,1,0,0};
    int dc[4] = {0,0,-1,1};
    void bfs(int row,int col,vector<vector<char>>& board,vector<vector<int>>& visited){
        int m = board.size();
        int n = board[0].size();

        queue<pair<int,int>>q;
        q.push({row,col});
        visited[row][col] = 1;

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                int nr = r+dr[i];
                int nc = c+dc[i];

                if(isvalid(nr,nc,m,n) && board[nr][nc] == 'O'&& visited[nr][nc] == 0){
                    visited[nr][nc] = 1;
                    q.push({nr,nc});
                }
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<int>>visited(m,vector<int>(n,0));

        // start bfs from the boundary cells
        // first and last column
        for(int i=0;i<m;i++){
            if(board[i][0] == 'O'){
                bfs(i,0,board,visited);
            }
            if(board[i][n-1] == 'O'){
                bfs(i,n-1,board,visited);
            }
        }

        // first and last row
        for(int j=0;j<n;j++){
            if(board[0][j] == 'O'){
                bfs(0,j,board,visited);
            }
            if(board[m-1][j] == 'O'){
                bfs(m-1,j,board,visited);
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){     
                if(board[i][j] == 'O' && visited[i][j] == 0){
                    board[i][j] = 'X';
                }
            }
        }

    }
};