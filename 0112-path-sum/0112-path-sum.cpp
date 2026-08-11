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
    bool solve(TreeNode* root,int target){
        if(root == NULL){
            return false;
        }

        if(root->left == NULL && root->right == NULL){
            // leaf nodes
            return target == root->val;
        }
        bool op1 = false;
        bool op2 = false;

        op1 = solve(root->left,target-root->val);
        op2 = solve(root->right,target-root->val);

        return op1 || op2;
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL){
            return false;
        }
        return solve(root,targetSum);
    }
};