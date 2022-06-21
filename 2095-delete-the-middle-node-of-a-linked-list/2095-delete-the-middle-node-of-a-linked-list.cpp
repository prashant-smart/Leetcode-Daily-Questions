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
    ListNode* deleteMiddle(ListNode* head) {
        
        int cnt=0;
        ListNode* ptr=head;
        while(ptr){
            cnt++;
            ptr=ptr->next;
        }
        if(cnt==1) return NULL;
        
        int tar=cnt/2;
        // cout<<tar;
        int c=0;
        ptr=head;
        while(c!=tar-1){
            
            c++;
            ptr=ptr->next;
        }
        ListNode* temp=ptr->next;
        ptr->next=ptr->next->next;
        // delete(temp);
        return head;
    }
};