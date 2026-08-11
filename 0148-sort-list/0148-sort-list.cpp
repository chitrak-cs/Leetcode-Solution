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
    ListNode* sortList(ListNode* head) {
        vector<int>nums;
        ListNode* p = head;
        while(p!=NULL){
            nums.push_back(p->val);
            p = p->next;
        }

        sort(nums.begin(),nums.end());
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        for(auto x:nums){
            ListNode* curr = new ListNode(x);
            tail->next = curr;
            tail = tail->next;
        }

        return dummy->next;
    }
};