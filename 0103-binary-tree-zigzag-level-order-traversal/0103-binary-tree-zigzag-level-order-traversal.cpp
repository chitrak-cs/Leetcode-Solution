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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
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

        int row = 0;
        int n = nodes.size();
        for(int i=0;i<n;i++){
            if(i%2 == 1){
                reverse(nodes[i].begin(),nodes[i].end());
            }
        }

        return nodes;
    }
};
