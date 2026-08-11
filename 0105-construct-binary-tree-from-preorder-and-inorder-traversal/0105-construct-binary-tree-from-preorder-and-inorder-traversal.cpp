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
    TreeNode* build(vector<int>& preorder,vector<int>& inorder,int& preindex,int left,int right){
        int n = preorder.size();
        if(preindex>=n || left>right) return NULL;

        int val = preorder[preindex];
        preindex++;


        TreeNode* root = new TreeNode(val);
        int index = left;
        while(index<right && inorder[index] != val) index++;

        root->left = build(preorder,inorder,preindex,left,index-1);
        root->right = build(preorder,inorder,preindex,index+1,right);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        int preindex = 0;
        return build(preorder,inorder,preindex,0,n-1);
    }
};