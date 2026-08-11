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
    void preorder(TreeNode* root,vector<int>& nums){
        if(root== NULL) return;
        nums.push_back(root->val);
        preorder(root->left,nums);
        preorder(root->right,nums);
    }
public:
    void flatten(TreeNode* root) {
        vector<int>nums;
        preorder(root,nums);

        int n = nums.size();
        for(int i=1;i<n;i++){
            root->left = NULL;
            root->right = new TreeNode(nums[i]);
            root = root->right;
        }
        
    }
};