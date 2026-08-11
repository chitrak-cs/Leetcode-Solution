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
    void func(TreeNode* root,string& number,vector<int>& nums){
        if(root == NULL){
            return;
        }

        int val = root->val;
        char ch = val + '0';
        number += ch;

        if(root->left == NULL && root->right == NULL){
            // leaf node is being reached
            int num = stoi(number);
            nums.push_back(num);
            number.pop_back();
            return;
        }

        func(root->left,number,nums);
        func(root->right,number,nums);
        number.pop_back();
    }
public:
    int sumNumbers(TreeNode* root) {
       string number = "";
       vector<int>nums;
       func(root,number,nums); 
       int ans = 0;
       for(int x:nums){
        ans += x;
       }
       return ans;
    }
};