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
    ListNode* reverseHelper(ListNode* head,ListNode* prev){
        ListNode* next=head->next;
        head->next=prev;
        prev=head;
        if(!next) return head;
        return reverseHelper(next,prev);
    }
    ListNode* reverseList(ListNode* head) {
        if(!head) return head;
        return reverseHelper(head,NULL);
    }
};