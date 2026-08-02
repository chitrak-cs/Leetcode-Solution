class Solution {
private:
    bool check(int row,int col,vector<vector<char>>& board){
        vector<int>freq(10);
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                int r = row + i;
                int c = col + j;

                int val = 0;
                if(board[r][c] != '.') val = board[r][c] - '0';
                freq[val]++;
            }
        }

        for(int i=1;i<=9;i++){
            if(freq[i] > 1) return false;
        }

        return true;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j] == '.') continue;
                char val = board[i][j];
                for(int row=0;row<9;row++){
                    if(row == i) continue;
                    if(board[row][j] == val) return false;
                }
                for(int col=0;col<9;col++){
                    if(col == j) continue;
                    if(board[i][col] == val) return false;
                }

            }
        }

        int dr[3] = {0,3,6};
        int dc[3] = {0,3,6};

        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                int nr = dr[i];
                int nc = dc[j];

                if(check(nr,nc,board) == false) return false;
            }
        }

        return true;
    }
};