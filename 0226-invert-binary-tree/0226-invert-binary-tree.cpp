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
    void func(TreeNode* root){
        if(root == NULL){
            return;
        }

        TreeNode* left = root->left;
        TreeNode* right = root->right;

        root->left = right;
        func(root->left);

        root->right = left;
        func(root->right);
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        func(root);
        return root;
    }
};