class Solution {
private:
    // function to calculate the number of live cells in the surrounding of a particular cell
    int dr[8] = {-1,-1,0,1,1,1,0,-1};
    int dc[8] = {0,1,1,1,0,-1,-1,-1};

    bool isvalid(int row, int col,int m, int n){
        if(row >= 0 && row <m && col>=0 && col<n) return true;
        return false;
    }

    int count(int row,int col,vector<vector<int>>& board){
        int cnt = 0;
        int m = board.size();
        int n = board[0].size();

        for(int i=0;i<8;i++){
            int nr = row + dr[i];
            int nc = col + dc[i];

            if(isvalid(nr,nc,m,n)){
                if(board[nr][nc] == 1) cnt++;
            } 
        }

        return cnt;
    }
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<int>>temp = board;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int ne = count(i,j,temp);
                if(board[i][j] == 1){
                    if(ne<2 || ne>3) board[i][j] = 0;
                }
                else{
                    if(ne == 3) board[i][j] = 1;
                }
            }
        }
    }
};