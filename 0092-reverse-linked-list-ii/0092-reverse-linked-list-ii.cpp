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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right) return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        head = dummy;
        ListNode* start = head;
        ListNode* end = head;

        for(int i=0;i<left;i++){
            start = start->next;
        }

        for(int i=0;i<right;i++){
            end = end->next;
        }

        unordered_map<ListNode*,ListNode*>parent;
        ListNode* p = head;
        ListNode* q = NULL;
        while(p!=NULL){
            parent[p] = q;
            q = p;
            p = p->next;
        }

        q = NULL;
        p = head;

        while(p!=start){
            q = p;
            p = p->next;
        }

        // node q is the previous node of p
        
        q->next = end;
        ListNode* rnext = end->next;
        while(end != start){
            end ->next = parent[end];
            end = parent[end];
        }
        start->next = rnext;

        return dummy->next;
        
    }
};