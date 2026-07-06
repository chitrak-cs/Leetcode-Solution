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
    int depth(TreeNode* root){
        if(root == NULL)
            return 0;

        return max(depth(root->left), depth(root->right)) + 1;
    }

    TreeNode* dfs(TreeNode* root){
        if(root == NULL)
            return NULL;

        int leftDepth = depth(root->left);
        int rightDepth = depth(root->right);

        if(leftDepth == rightDepth)
            return root;

        if(leftDepth > rightDepth)
            return dfs(root->left);

        return dfs(root->right);
    }
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return dfs(root)      ;
    }
};