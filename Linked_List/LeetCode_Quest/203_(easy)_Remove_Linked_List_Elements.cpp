
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL ) return head;
        ListNode* fake=new ListNode(10);
        ListNode* temp=fake;
        ListNode* temp1=head;
        while(temp1!=NULL){
            if(temp1->val==val){
                temp1=temp1->next;
                temp->next=NULL;
            }else{
                temp->next=temp1;
                temp=temp1;
                temp1=temp1->next;
            }
        }
        return fake->next;
    }
};