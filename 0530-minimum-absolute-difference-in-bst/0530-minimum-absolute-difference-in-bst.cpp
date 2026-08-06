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
    void inorder(TreeNode* root,vector<int>& node){
        if(root == NULL){
            return;
        }
        inorder(root->left,node);
        node.push_back(root->val);
        inorder(root->right,node);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        // inorder traversal in BST is in ascending order
        vector<int>node;
        inorder(root,node);

        int ans = INT_MAX;
        int n = node.size();
        for(int i=1;i<n;i++){
            int diff = node[i] - node[i-1];
            ans = min(ans,diff);
        }

        return ans;
    }
};