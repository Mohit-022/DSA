
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* odd=new ListNode(0);
        ListNode* even=new ListNode(0);
        ListNode* temp=head;
        ListNode* tempA=odd;
        ListNode* tempB=even;
        while(temp!=NULL){
            if(temp!=NULL){
                tempA->next=temp;
                tempA=tempA->next;
                temp=temp->next;
            }
            if(temp!=NULL){
                tempB->next=temp;
                tempB=tempB->next;
                temp=temp->next;
            }
        }
        tempA->next=NULL;
        tempB->next=NULL;
        odd=odd->next;
        even=even->next;
        tempA->next=even;
        return head;

    }
};