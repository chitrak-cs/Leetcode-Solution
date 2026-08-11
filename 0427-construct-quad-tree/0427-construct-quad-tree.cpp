/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
private:
    Node* build(int row,int col,int size,vector<vector<int>>& grid){
        bool same = true;
        int value = grid[row][col];

        for(int i=row;i<row+size;i++){
            for(int j=col;j<col+size;j++){
                if(grid[i][j] != value){
                    same = false;
                    break;
                }
            }
        }

        if(same){
            bool val;
            if(value == 1){
                val = true;
            }
            else val = false;
            Node* head = new Node(val,true);
            return head;
        }

        int half = size/2;
        Node* root = new Node(true,false);
        root->topLeft = build(row,col,half,grid);
        root->topRight = build(row,col+half,half,grid);
        root->bottomLeft = build(row+half,col,half,grid);
        root->bottomRight = build(row+half,col+half,half,grid);

        return root;
    }
public:
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        return build(0,0,n,grid);
    }
};