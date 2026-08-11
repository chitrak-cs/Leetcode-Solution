/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        vector<vector<Node*>>nodes;
        queue<Node*>q;
        if(root == NULL) return root;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<Node*>temp;
            while(size--){
                Node* curr = q.front();
                q.pop();

                temp.push_back(curr);

                if(curr->left){
                    q.push(curr->left);
                }

                if(curr->right){
                    q.push(curr->right);
                }
            }
            nodes.push_back(temp);
        }

        for(auto temp:nodes){
            int n = temp.size();
            for(int i=0;i<n-1;i++){
                temp[i]->next = temp[i+1];
            }
        }

        return root;


    }
};