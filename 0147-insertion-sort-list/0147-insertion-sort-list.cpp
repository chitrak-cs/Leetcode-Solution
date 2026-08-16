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
    ListNode*  insert(ListNode* head,int val){
        // this function takes the head of a sorted linked list and insert an node such that the list remain sorted
        ListNode* curr = new ListNode(val);
        if(curr->val < head->val){
            // return to the front of the node
            curr->next = head;
            head = curr;
            return head;
        }

        ListNode* p = head;
        while(p->next != NULL && curr->val > p->next->val){
            p = p->next;
        }

        curr->next = p->next;
        p->next = curr;
        return head;
    }
public:
    ListNode* insertionSortList(ListNode* head) {
        int first = head->val;
        ListNode* ans = new ListNode(first);
        ListNode* p = head;

        while(p->next!=NULL){
            p = p->next;
            int val = p->val;
            ans = insert(ans,val);
        }

        return ans;
    }
};