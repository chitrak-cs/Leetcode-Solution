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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode* p = head->next;
        ListNode* tail = NULL;
        ListNode* q = head;
        head = head->next;

        while(p!=NULL && q!=NULL){
            q->next = p->next;
            p->next = q;

            if(tail != NULL)
                tail->next = p;

            tail = q;


            q = q->next;
            p = q;
            if(p == NULL || p->next == NULL){
                break;
            }
            p = p->next;
        }
        return head;
    }
};