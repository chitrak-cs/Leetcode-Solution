/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* p = head;
        int cnt = 0;
        while(p!=NULL){
            cnt++;
            p =p->next;
        }
        int each = cnt/k;
        int rem = cnt % k;
        vector<int>lenghts(k,each);
        vector<ListNode*>ans(k);

        int ind=0;
        while(rem--){
            lenghts[ind]++;
            ind++;
        }

        p = head;
        ListNode* q = NULL;
        ind = 0;
        while(p!=NULL){
            int k = lenghts[ind];
            ans[ind] = p;
            for(int i=0;i<k;i++){
                q = p;
                p = p->next;
            }
            q->next = NULL;
            ind++;
        }

        return ans;
    }
};