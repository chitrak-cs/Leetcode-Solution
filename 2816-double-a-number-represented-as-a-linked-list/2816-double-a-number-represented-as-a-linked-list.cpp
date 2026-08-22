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
private:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode* p = head;
        ListNode* q = NULL;
        ListNode* r = NULL;

        while(p!= NULL){
            r = q;
            q = p;
            p = p->next;
            q->next = r;

        }

        return q;
    }
public:
    ListNode* doubleIt(ListNode* head) {
        head = reverseList(head);
        int carry = 0;
        ListNode* p = head;
        ListNode* prev = NULL;
        while(p!=NULL){
            int val = p->val;
            val *= 2;
            val += carry;
            if(val<=9){
                p->val = val;
                carry = 0;
            }
            else{
                carry = 1;
                val -= 10;
                p->val = val;
            }
            prev = p;
            p = p->next;
        }
        if(carry == 1){
            ListNode* q = new ListNode(carry);
            prev->next = q;
        }
        head = reverseList(head);
        return head;
    }
};