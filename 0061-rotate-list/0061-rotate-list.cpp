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
    ListNode* rotateRight(ListNode* head, int k) {

        if(head == NULL || head->next == NULL) return head;
        if(k == 0) return head;
        
        int cnt = 1;
        ListNode* p = head;
        while(p->next!=NULL){
            p = p->next;
            cnt++;
        }

        k = k%cnt;

        
        p->next = head;
        p = head;
        int index = cnt - k;
        for(int i=0;i<index-1;i++){
            p = p->next;
        }

        head = p->next;
        p->next = NULL;

        return head;
    }
};