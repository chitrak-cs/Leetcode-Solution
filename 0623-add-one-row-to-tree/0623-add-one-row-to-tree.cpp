/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    void dfs(TreeNode* root, int val, int depth, int curdepth){
        if(root == NULL){
            return;
        }

        if(curdepth < depth -1){
            dfs(root->left,val,depth,curdepth+1);
            dfs(root->right,val,depth,curdepth+1);
        }

        if(curdepth == depth-1){
            TreeNode* prevleft = root->left;
            TreeNode* prevright = root->right;

            TreeNode* leftchild = new TreeNode(val);
            TreeNode* rightchild = new TreeNode(val);

            root->left = leftchild;
            leftchild->left = prevleft;

            root->right = rightchild;
            rightchild->right = prevright;
        }
    }
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode* newnode = new TreeNode(val);
            newnode->left = root;
            return newnode;
        }
        dfs(root,val,depth,1);
        return root;
    }
};