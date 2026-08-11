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
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<vector<int>>nodes;
        queue<TreeNode*>q;
        q.push(root);


        if(root == NULL){
            return {};
        }

        while(!q.empty()){
            int size = q.size();
            vector<int>levels;
            while(size--){
                TreeNode* node = q.front();
                levels.push_back(node->val);
                q.pop();

                if(node->left){
                    q.push(node->left);
                }

                if(node->right){
                    q.push(node->right);
                }
            }
            nodes.push_back(levels);
        }

        int n = nodes.size();
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            int m = nodes[i].size();
            ans[i] = nodes[i][m-1];
        }

        return ans;
    }
};