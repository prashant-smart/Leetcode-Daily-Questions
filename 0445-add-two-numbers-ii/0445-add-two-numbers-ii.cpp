class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1;
        stack<int> s2;
        ListNode* ptr=l1;
        while(ptr){
            s1.push(ptr->val);
            ptr=ptr->next;
        }
        ptr=l2;
        while(ptr){
            s2.push(ptr->val);
            ptr=ptr->next;
        }
        stack<int> s3;
        int c=0;
        while(s1.size()||s2.size()){
            int n1=(s1.size())?s1.top():0;
            int n2=(s2.size())?s2.top():0;
            if(s1.size())
                s1.pop();
            if(s2.size())
                s2.pop();
            int sum=n1+n2+c;
            s3.push(sum%10);
            c=sum/10;
            // cout<<c<<" ";
        }
        while(c){
            s3.push(c%10);
            c/=10;
        }
        
        ListNode* head=new ListNode(s3.top());
        ptr=head;
        s3.pop();
        while(s3.size()){
            ptr->next=new ListNode(s3.top());
            s3.pop();
            ptr=ptr->next;
        }
        
        return head;
    }
};