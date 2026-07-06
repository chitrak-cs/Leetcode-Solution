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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return dfs(root);
    }
};