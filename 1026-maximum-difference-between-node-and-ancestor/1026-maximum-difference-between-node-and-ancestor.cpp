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
    int dfs(TreeNode* root, int maxval, int minval){
        if(root == NULL){
            return maxval - minval;
        }

        int val = root->val;
        maxval = max(maxval,val);
        minval = min(minval,val);

        int left = dfs(root->left,maxval,minval);
        int right = dfs(root->right,maxval,minval);

        return max(left,right);
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        int maxval = INT_MIN;
        int minval = INT_MAX;

        return dfs(root,maxval,minval);
    }
};